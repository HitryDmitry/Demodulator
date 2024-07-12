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
    // UnorderedMap<int, std::string> m2 = {{1, "foo"}, {3, "bar"}, {2, "baz"}};
    // std::unordered_map<int, std::string> m = {{1, "foo"}, {3, "bar"}, {2, "baz"}};
    // // copy constructor
    // std::unordered_map<int, std::string> m3 = m2;

    // // move constructor
    // std::unordered_map<int, std::string> m4 = std::move(m2);

    // insert function
    m1.insert("city", "Moscow");
    m1.insert("country", "Russia");
    m1.insert("city", "Beijing");
}
