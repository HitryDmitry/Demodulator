#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// структура элемента
template <typename Key, typename Value>
struct Item {
    Key* key;
    Value* value;
};

// структура связанного списка для обработки коллизий
template <typename Key, typename Value>
struct LinkedList {
    Item<Key, Value>* item;
    LinkedList* next;
};

// функция для создания списка
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
        head->item                   = item;
        head->next                   = nullptr;
        list                         = head;
        return list;
    }

    else if(list->next == nullptr) {
        LinkedList<Key, Value>* node = allocate_list<Key, Value>();
        node->item                   = item;
        node->next                   = nullptr;
        list->next                   = node;
        return list;
    }

    LinkedList<Key, Value>* temp = list;
    while(temp->next->next) {
        temp = temp->next;
    }

    LinkedList<Key, Value>* node = allocate_list<Key, Value>();
    node->item                   = item;
    node->next                   = nullptr;
    temp->next                   = node;

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
    temp->next                   = nullptr;
    list                         = node;

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
#endif // LINKEDLIST_H
