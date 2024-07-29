#include <gtest/gtest.h>
#include "unorderedmap.h"

#include <iostream>
/**
 * @brief тестируем конструктор
 */
TEST(DemodulatorTest, TestUnorderedMapObjectCreation)
{
    UnorderedMap<const char*, const char*>* ht = new UnorderedMap<const char*, const char*>(0);
    ht->insert("1", "First address");
    ht->insert("2", "Second address");
    ht->insert("Hel", "Third address");
    ht->insert("5", "Five");
    ht->insert("6", "Six");
    ht->insert("Cau", "Fourth address");

    std::cout << ht->search("Hel") << std::endl;
    // std::cout << ht->search("1") << std::endl;
    // std::cout << ht->search("2") << std::endl;
    // std::cout << ht->search("5") << std::endl;
    // std::cout << ht->search("6") << std::endl;
    ht->remove("Cau");
    if(ht->search("Cau"))
        std::cout << ht->search("Cau") << std::endl;
    ht->print_table();

    delete ht;
}
