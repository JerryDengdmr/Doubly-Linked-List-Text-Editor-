#include "List.hpp"
#include "unit_test_framework.hpp"
using namespace std;
TEST(test_list_default_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}
TEST(test_push_front_empty) {
    List<int> list;
    list.push_front(42);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 42);
    ASSERT_EQUAL(list.back(), 42);
}
TEST(test_push_back_empty) {
    List<int> list;
    list.push_back(42);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 42);
    ASSERT_EQUAL(list.back(), 42);
}
TEST(test_push_front_multiple) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}
TEST(test_push_back_multiple) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}
TEST(test_pop_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);
}
TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
}
TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}
TEST(test_iterator_begin_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());
}
TEST(test_iterator_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        ASSERT_EQUAL(*it, j);
        ++j;
    }
    ASSERT_EQUAL(j, 5);
}
TEST(test_copy_constructor) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2(list1);
    ASSERT_EQUAL(list2.size(), 3);
    ASSERT_EQUAL(list2.front(), 1);
    ASSERT_EQUAL(list2.back(), 3);
    list1.pop_front();
    ASSERT_EQUAL(list1.size(), 2);
    ASSERT_EQUAL(list2.size(), 3);
}
TEST(test_assignment_operator) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    List<int> list2;
    list2.push_back(99);
    list2 = list1;
    ASSERT_EQUAL(list2.size(), 3);
    ASSERT_EQUAL(list2.front(), 1);
    ASSERT_EQUAL(list2.back(), 3);
    list1.pop_front();
    ASSERT_EQUAL(list1.size(), 2);
    ASSERT_EQUAL(list2.size(), 3);
}
TEST(test_insert_middle) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.insert(it, 2);
    ASSERT_EQUAL(list.size(), 3);
    it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}
TEST(test_insert_front) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    list.insert(list.begin(), 1);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
}
TEST(test_insert_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(list.end(), 3);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.back(), 3);
}
TEST(test_erase_middle) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 3);
}
TEST(test_erase_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(list.begin());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
}
TEST(test_string_list) {
    List<string> list;
    list.push_back("hello");
    list.push_back("world");
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), "hello");
    ASSERT_EQUAL(list.back(), "world");
}
TEST(test_empty_list_operations) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.begin() == list.end());
}
TEST_MAIN()

TEST(test_pop_front_to_empty) {
    List<int> list;
    list.push_back(1);
    list.pop_front();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_TRUE(list.begin() == list.end());
}

TEST(test_pop_back_to_empty) {
    List<int> list;
    list.push_back(1);
    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_TRUE(list.begin() == list.end());
}

TEST(test_push_pop_alternating) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    list.push_back(3);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_iterator_decrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.end();
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
    ASSERT_TRUE(it == list.begin());
}

TEST(test_iterator_postfix_increment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.begin();
    List<int>::Iterator old = it++;
    ASSERT_EQUAL(*old, 1);
    ASSERT_EQUAL(*it, 2);
}

TEST(test_iterator_postfix_decrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.end();
    --it;
    List<int>::Iterator old = it--;
    ASSERT_EQUAL(*old, 2);
    ASSERT_EQUAL(*it, 1);
}

TEST(test_erase_last_element) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    ++it;
    List<int>::Iterator result = list.erase(it);
    ASSERT_TRUE(result == list.end());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_erase_all_elements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(list.begin());
    list.erase(list.begin());
    list.erase(list.begin());
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_insert_empty_list) {
    List<int> list;
    list.insert(list.end(), 42);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 42);
    ASSERT_EQUAL(list.back(), 42);
}

TEST(test_self_assignment) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int> &ref = list;
    list = ref;
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_copy_empty_list) {
    List<int> list1;
    List<int> list2(list1);
    ASSERT_TRUE(list2.empty());
    ASSERT_EQUAL(list2.size(), 0);
}

TEST(test_assign_empty_list) {
    List<int> list1;
    list1.push_back(1);
    List<int> list2;
    list1 = list2;
    ASSERT_TRUE(list1.empty());
    ASSERT_EQUAL(list1.size(), 0);
}

TEST(test_multiple_clears) {
    List<int> list;
    list.push_back(1);
    list.clear();
    list.clear();
    ASSERT_TRUE(list.empty());
    list.push_back(2);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 2);
}

TEST(test_iterator_equality) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2 = list.begin();
    ASSERT_TRUE(it1 == it2);
    ++it2;
    ASSERT_FALSE(it1 == it2);
}

TEST(test_default_iterator_equality) {
    List<int>::Iterator it1;
    List<int>::Iterator it2;
    ASSERT_TRUE(it1 == it2);
}

TEST(test_large_list) {
    List<int> list;
    for (int i = 0; i < 100; ++i) {
        list.push_back(i);
    }
    ASSERT_EQUAL(list.size(), 100);
    ASSERT_EQUAL(list.front(), 0);
    ASSERT_EQUAL(list.back(), 99);
    int count = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        ASSERT_EQUAL(*it, count);
        ++count;
    }
}
