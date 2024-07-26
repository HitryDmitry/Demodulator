#include <gtest/gtest.h>
#include "unorderedmap.h"

#include <iostream>
/**
 * @brief тестируем конструктор
 */
TEST(DemodulatorTest, TestUnorderedMapObjectCreation)
{
    HashTable<const char*, const char*>* ht = create_table<const char*, const char*>();
    ht->insert("1", "First address");
    ht->insert("2", "Second address");
    ht->insert("Hel", "Third address");
    ht->insert("5", "Five");
    ht->insert("6", "Six");
    ht->insert("Cau", "Fourth address");

    // std::cout << ht->search("Hel") << std::endl;
    // std::cout << ht->search("1") << std::endl;
    // std::cout << ht->search("2") << std::endl;
    // std::cout << ht->search("5") << std::endl;
    // std::cout << ht->search("6") << std::endl;
    ht->remove("Cau");
    if(ht->search("Cau"))
        std::cout << ht->search("Cau") << std::endl;
    ht->print_table();
    free_table(ht);

    // HashTable<const char*, int>* ht1 = create_table<const char*, int>();
    // ht1->insert("1", 1);
    // ht1->insert("2", 2);
    // // ht1->insert("Hel", 5);
    // // ht1->insert("Cau", 6);
    // std::cout << ht1->search("Cau") << std::endl;
    // std::cout << ht1->search("Hel") << std::endl;
    // // ht1->remove("1");
    // // ht1->remove("2");
    // // std::cout << ht1->search("1") << std::endl;
    // // std::cout << ht1->search("2") << std::endl;
}
