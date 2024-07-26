#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H
#include <iostream>
#include <cstdint>
#include <cstring>
#include <unordered_map>
#include "UnorderedMap_global.h"


// таблица для рехэширования
const int rehashing_table[51] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 103, 109, 113, 127, 137,
    139, 149, 157, 167, 179, 193, 199, 211, 227, 241,
    257, 277, 293, 313, 337, 359, 383, 409, 439, 467, 503
};

#define CAPACITY 50000

// структура элемента
template <typename Key, typename Value>
struct Item {
    Key* key;
    Value* value;
};

// функция, очищающая память элемента
template <typename Key, typename Value>
void free_item(Item<Key, Value>* item)
{
    delete item->key;
    delete item->value;
    delete item;
}

// структура связанного списка для обработки коллизий
template <typename Key, typename Value>
struct LinkedList {
    Item<Key, Value>* item;
    LinkedList* next;
};

// функиция для создания списка
template <typename Key, typename Value>
LinkedList<Key, Value>* allocate_list()
{
    LinkedList<Key, Value>* list = new LinkedList<Key, Value>();
    return list;
}

// вставка элемента в список
template <typename Key, typename Value>
LinkedList<Key, Value>* linkedlist_insert(LinkedList<Key, Value>* list, Item<Key, Value>* item)
{
    if(!list) {
        LinkedList<Key, Value>* head = allocate_list<Key, Value>();
        head->item       = item;
        head->next       = nullptr;
        list             = head;
        return list;
    }

    else if(list->next == nullptr) {
        LinkedList<Key, Value>* node = allocate_list<Key, Value>();
        node->item       = item;
        node->next       = nullptr;
        list->next       = node;
        return list;
    }

    LinkedList<Key, Value>* temp = list;
    while(temp->next->next) {
        temp = temp->next;
    }

    LinkedList<Key, Value>* node = allocate_list<Key, Value>();
    node->item       = item;
    node->next       = nullptr;
    temp->next       = node;

    return list;
}

// удаление элемента из списка
template <typename Key, typename Value>
Item<Key, Value>* linkedlist_remove(LinkedList<Key, Value>* list)
{
    if(!list)
        return nullptr;
    if(!list->next)
        return nullptr;
    LinkedList<Key, Value>* node = list->next;
    LinkedList<Key, Value>* temp = list;
    temp->next       = nullptr;
    list             = node;

    Item<Key, Value>* it = nullptr;
    std::memcpy(temp->item, it, sizeof(Item<Key, Value>));
    delete temp->item->key;
    delete temp->item->value;
    delete temp->item;
    delete temp;
    return it;
}

// функция для освобождения списка
template <typename Key, typename Value>
void free_linkedlist(LinkedList<Key, Value>* list)
{
    LinkedList<Key, Value>* temp = list;
    while(list) {
        temp = list;
        list = list->next;
        delete temp->item->key;
        delete temp->item->value;
        delete temp->item;
        delete temp;
    }
}

// структура хэш-таблицы
template <typename Key, typename Value>
struct HashTable {
public:
    // функция для создания элемента
    Item<Key, Value>* create_item(Key key, Value value)
    {
        Item<Key, Value>* item = new Item<Key, Value>();
        item->key              = new Key(key);
        item->value            = new Value(value);
        return item;
    }

    void remove(Key key){
        int index = hash_function(key);
        Item<Key, Value>* item = this->items[index];
        LinkedList<Key, Value>* head = this->overflow_buckets[index];

        if (item != nullptr){
            // Если нет коллизий
            if (head == nullptr && *item->key == key){
                this->items[index] = nullptr;
                free_item(item);
                this->count--;
            }
            // Есть коллизии
            else if (head != nullptr){
                if (*item->key == key) {
                    free_item(item);
                    LinkedList<Key, Value>* node = head;
                    head = head->next;
                    node->next = nullptr;
                    this->items[index] = create_item(*node->item->key, *node->item->value);
                    free_linkedlist(node);
                    this->overflow_buckets[index] = head;
                }
            }

            LinkedList<Key, Value>* curr = head;
            LinkedList<Key, Value>* prev = nullptr;


            while (curr) {
                if (*curr->item->key == key) {
                    if (prev == nullptr) {
                        // First element of the chain. Remove the chain
                        free_linkedlist(head);
                        this->overflow_buckets[index] = nullptr;
                        return;
                    }
                    else {
                        // This is somewhere in the chain
                        prev->next = curr->next;
                        curr->next = nullptr;
                        free_linkedlist(curr);
                        this->overflow_buckets[index] = head;
                        return;
                    }
                }
                curr = curr->next;
                prev = curr;
            }
        }
    }

    // функция для обработки коллизий
    void handle_collision(HashTable<Key, Value>* table, unsigned long index, Item<Key, Value>* item)
    {
        LinkedList<Key, Value>* head = table->overflow_buckets[index];
        // Первый сценарий. Если список элемента не существует, нам нужно создать такой список и добавить в него элемент
        if (head == NULL){
            head = allocate_list<Key, Value>();
            head->item = item;
            table->overflow_buckets[index] = head;
        }
        // Второй сценарий. Просто вставляем элемент в список
        else{
            table->overflow_buckets[index] = linkedlist_insert(head, item);
        }
    }

    // функция для вставки в хэш-таблицу
    void insert(Key key, Value value)
    {
        // создаем объект
        Item<Key, Value>* item = create_item(key, value);
        // получаем индекс для вставки
        int index = hash_function(key);

        // если полученный индекс больше размера таблицы - рехэшируем
        if (index > this->size){
            rehash(index);
        }
        ///!!!!!! проверить, что функция rehash корректно все копирует!!!!
        Item<Key, Value>* current_item = this->items[index];

        // если такого элемента еще не существует
        if(current_item == NULL) {
            // таблица уже наполнена
            if(this->count == this->size) {
                rehash(this->size + 1);
            }

            // вставка
            this->items[index] = item;
            this->count++;
        }
        else {
            if(*current_item->key == key) {
                // ситуация 1: обновляем значение по уже существующему ключу
                this->items[index]->value = &value;
            }
            else {
                // ситуация 2: коллизия. Добавляем элемент в список за уже существующим
                handle_collision(this, index, item);
            }
        }
    }

    // функция для поиска
    Value search(Key key)
    {
        int index              = hash_function(key);
        Item<Key, Value>* item = this->items[index];
        LinkedList<Key, Value>* head = this->overflow_buckets[index];

        while (item != nullptr){
            if (*item->key == key) {
                return *item->value;
            }
            if (head == nullptr){
                return NULL;
            }
            item = head->item;
            head = head->next;
        }
        return NULL;
    }

    void print_table()
    {
        printf("\nHash Table\n-------------------\n");
        for(int i = 0; i < this->size; i++) {
            if(this->items[i]) {
                printf("Index:%d, Key:%s, Value:%s\n", i, *this->items[i]->key, *this->items[i]->value);
            }
        }
        printf("-------------------\n\n");
    }


    LinkedList<Key, Value>** overflow_buckets;
    Item<Key, Value>** items;
    int size;
    int count;
    int index_in_rehashing_table;

    // функция для создания переполненных корзин
    LinkedList<Key, Value>** create_overflow_buckets()
    {
        // Create the overflow buckets; an array of linkedlists
        LinkedList<Key, Value>** buckets = new(LinkedList<Key, Value>* [this->size]);
        for(int i = 0; i < this->size; i++)
            buckets[i] = NULL;
        return buckets;
    }

    // функция для освобождения переполненных корзин
    void free_overflow_buckets()
    {
        // Free all the overflow bucket lists
        LinkedList<Key, Value>** buckets = this->overflow_buckets;
        for(int i = 0; i < this->size; i++)
            free_linkedlist(buckets[i]);
        delete[] buckets;
    }

    // функция для копирования элементов из старого массива в новый
    void rewriteItems(int old_size, int new_size){
        Item<Key, Value>** new_items = new(Item<Key, Value>* [this->size]);
        Item<Key, Value>** old_items = this->items;
        // заполняем нулевыми указателями новый массив
        for(int i = 0; i < new_size; i++){
            new_items[i] = nullptr;
        }

        // копируем старые значения элементов в новый массив указателей с новыми хэшами
        for(int i = 0; i < old_size; i++){
            new_items[i] = old_items[i];
        }
        // обновляем массив у текущего объекта
        this->items = new_items;
        // удаляем старый
        for (int i = 0; i < old_size; ++i){
            if(old_items[i])
                free_item(old_items[i]);
        }
        delete[] old_items;
    }

    void rewriteOverflowBuckets(int old_size){
        // создаем новый массив переполненных корзин
        LinkedList<Key, Value>** new_list = create_overflow_buckets();
        // копируем туда значения из старого
        for(int i = 0; i < old_size; i++){
            new_list[i] = this->overflow_buckets[i];
        }
        LinkedList<Key, Value>** ptr_to_old_list = this->overflow_buckets;
        // обновляем значение списка коллизий
        this->overflow_buckets = new_list;
        // удаляем старый список
        for (int i = 0; i < old_size; i++){
            free_linkedlist(ptr_to_old_list[i]);
        }
        delete[] ptr_to_old_list;
    }

    // поиск подходящего размера по переданному индексу
    int find_value_rehashing_table(int index){
        int ind_rehash_table = 0;
        while (index > rehashing_table[ind_rehash_table]){
            ++ind_rehash_table;
        }
        return ind_rehash_table;
    }

    // функция для рехэширования
    void rehash(int index){
        int old_size = this->size;
        this->index_in_rehashing_table = find_value_rehashing_table(index);
        this->size = rehashing_table[this->index_in_rehashing_table];
        int new_size = this->size;
        rewriteItems(old_size, new_size);
        rewriteOverflowBuckets(old_size);
    }

    // хэш-функция
    unsigned long hash_function(const char* str)
    {
        unsigned long i = 0;
        for(int j = 0; str[j]; j++)
            i += str[j];
        return i % CAPACITY;
    }
};

// функция для создания хэш-таблицы
template <typename Key, typename Value>
HashTable<Key, Value>* create_table()
{
    HashTable<Key, Value>* table = new HashTable<Key, Value>();
    table->index_in_rehashing_table = 0;
    int size = rehashing_table[table->index_in_rehashing_table];
    table->size                  = size;
    table->count                 = 0;
    table->items                 = new(Item<Key, Value>* [size]);
    for(int i = 0; i < table->size; i++)
        table->items[i] = nullptr;

    table->overflow_buckets = table->create_overflow_buckets();
    return table;
}

// функция, очищающая память таблицы
template <typename Key, typename Value>
void free_table(HashTable<Key, Value>* table)
{
    for(int i = 0; i < table->size; i++) {
        Item<Key, Value>* item = table->items[i];
        if(item != nullptr) {
            free_item(item);
        }
    }

    table->free_overflow_buckets();
    delete[] table->items;
    delete table;
}

// #include "unorderedmap.cpp"
#endif // UNORDEREDMAP_H
