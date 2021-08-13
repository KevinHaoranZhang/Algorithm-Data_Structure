#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Linked_list/Singly/singly.h"

TEST_F(BST_test, insert) {
    Singly* head = Singly();
    head.insert_head(&head, 1);
    EXPECT_EQ(1, head->data);
}