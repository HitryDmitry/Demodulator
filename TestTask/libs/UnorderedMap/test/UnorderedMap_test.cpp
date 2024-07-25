#include <gtest/gtest.h>
#include "unorderedmap.h"

#include <iostream>
/**
 * @brief тестируем конструктор
 */
TEST(DemodulatorTest, TestUnorderedMapObjectCreation)
{
    HashTable<const char*, const char*>* ht = create_table<const char*, const char*>(1000);
    ht->insert("1", "First address");
    ht->insert("2", "Second address");
    ht->insert("Hel", "Third address");
    ht->insert("Cau", "Fourth address");
    std::cout << ht->search("Cau") << std::endl;
    std::cout << ht->search("Hel") << std::endl;
    // std::cout << ht->search("3") << std::endl;
    // ht->print_table();
    free_table(ht);
}
