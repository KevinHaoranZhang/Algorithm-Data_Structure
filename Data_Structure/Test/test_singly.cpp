#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Linked_List/Singly/singly.h"

using testing::Eq;

TEST(Singly_test, insert) {
    Singly* head = nullptr;
    head->insert_head(&head, 2);
    head->insert_head(&head, 1);
    head->insert_after(head->next, 4);
    head->insert_after(head->next, 3);
    head->insert_tail(&head, 5);
    head->insert_tail(&head, 6);
}