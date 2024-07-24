#include <gtest/gtest.h>
#include "unorderedmap.h"

/**
 * @brief тестируем конструктор
 */
TEST(DemodulatorTest, TestUnorderedMapObjectCreation)
{
    // default constructor: empty map
    UnorderedMap<std::string, std::string> m1;
    // UnorderedMap<std::string, std::string> m(std::string("Hello"), std::string("world"));

    // list constructor
    // UnorderedMap<int, std::string> m2 = {{0, "foo"}, {3, "bar"}, {2, "baz"}};
    UnorderedMap<int, std::string> m2 = {0, "foo"};
    std::string one                   = m2.get(0);
    std::string three                 = m2.get(3);
    // // list constructor from STL
    // std::unordered_map<int, std::string> m = {{1, "foo"}, {3, "bar"}, {2, "baz"}};

    // insert function
    m1.insert("city", "Moscow");
    m1.insert("city", "London");
    m1.insert("city", "Beijing");

    m1.insert("fruit", "Apple");

    // Конструктор копирования
    UnorderedMap<std::string, std::string> m3 = m1;

    std::string m1_city1 = m1.get("city");
    m1.remove("city");
    std::string m1_city2 = m1.get("city");
    // m1.remove("city");
    // std::string m1_city3 = m1.get("city");

    // std::string city  = m1.get("city");
    // std::string apple = m1.get("fruit");

    std::string m3_city1 = m3.get("city");
    m3.remove("city");
    std::string m3_city2 = m3.get("city");
    // std::string m3_apple = m3.get("fruit");

    //--------------------- из стандартной библиотеки-----------
    // // copy constructor
    // std::unordered_map<int, std::string> m3 = m2;

    // // move constructor
    // std::unordered_map<int, std::string> m4 = std::move(m2);
    //----------------------------------------------------------
}
