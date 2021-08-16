#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Linked_List/Singly/singly.h"

using testing::Eq;

class Singly_test : public testing::Test {
public:
    Singly* build_singly();
};

Singly* Singly_test::build_singly() {
    // build the following linked list:
    // 1->2->3->4->5
    Singly* node1 = new Singly(1);
    Singly* node2 = new Singly(2);
    Singly* node3 = new Singly(3);
    Singly* node4 = new Singly(4);
    Singly* node5 = new Singly(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    return node1;
}

TEST_F(Singly_test, insert) {
    Singly* head = nullptr;
    head->insert_head(head, 2);
    head->insert_head(head, 1);
    head->insert_after(head->next, 4);
    head->insert_after(head->next, 3);
    head->insert_tail(head, 5);
    head->insert_tail(head, 6);
    EXPECT_EQ(head->data, 1);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 3);
    EXPECT_EQ(head->next->next->next->data, 4);
    EXPECT_EQ(head->next->next->next->next->data, 5);

}

TEST_F(Singly_test, search) {
    Singly* head = build_singly();
    // test for iterative search
    EXPECT_EQ(true, head->search_iterative(head, 1));
    EXPECT_EQ(true, head->search_iterative(head, 3));
    EXPECT_EQ(true, head->search_iterative(head, 5));
    EXPECT_EQ(false, head->search_iterative(head, 0));
    EXPECT_EQ(false, head->search_iterative(head, 6));
    EXPECT_EQ(false, head->search_iterative(head, 10));
    // test for recursive search
    EXPECT_EQ(true, head->search_recursive(head, 1));
    EXPECT_EQ(true, head->search_recursive(head, 3));
    EXPECT_EQ(true, head->search_recursive(head, 5));
    EXPECT_EQ(false, head->search_recursive(head, 0));
    EXPECT_EQ(false, head->search_recursive(head, 6));
    EXPECT_EQ(false, head->search_recursive(head, 10));
}

TEST_F(Singly_test, delete) {
    // test for iterative delete
    Singly* head_iterative = build_singly();
    head_iterative->delete_iterative(head_iterative, 1);
    head_iterative->delete_iterative(head_iterative, 5);
    EXPECT_EQ(head_iterative->data, 2);
    EXPECT_EQ(head_iterative->next->data, 3);
    EXPECT_EQ(head_iterative->next->next->data, 4);
    Singly* head_recursive = build_singly();
    // test for iterative delete
    head_recursive->delete_recursive(head_recursive, 1);
    head_recursive->delete_recursive(head_recursive, 5);
    EXPECT_EQ(head_recursive->data, 2);
    EXPECT_EQ(head_recursive->next->data, 3);
    EXPECT_EQ(head_recursive->next->next->data, 4);
}