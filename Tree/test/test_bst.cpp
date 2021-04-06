#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../BST/BST.h"
#include <string>
#include <iostream>


using testing::Eq;

class BST_test : public testing::Test {
public:
    BST* build_bst_iterative();
    BST* build_bst_recursive();
};

BST* BST_test::build_bst_iterative() {
    BST bst, *root = NULL;
    root = bst.insert_iterative(root, 5);
    root = bst.insert_iterative(root, 3);
    bst.insert_iterative(root, 2);
    bst.insert_iterative(root, 4);
    bst.insert_iterative(root, 7);
    bst.insert_iterative(root, 6);
    bst.insert_iterative(root, 8);
    return root;
}

BST* BST_test::build_bst_recursive() {
    BST bst, *root = NULL;
    root = bst.insert_recursive(root, 5);
    root = bst.insert_recursive(root, 3);
    bst.insert_recursive(root, 2);
    bst.insert_recursive(root, 4);
    bst.insert_recursive(root, 7);
    bst.insert_recursive(root, 6);
    bst.insert_recursive(root, 8);
    return root;
}

TEST_F(BST_test, traversal) {
    BST* root = build_bst_iterative();
    root->preorder_iterative(root);
    root->preorder_recursive(root);
    root->inorder_iterative(root);
    root->inorder_recursive(root);
    root->postorder_iterative(root);
    root->postorder_recursive(root);
}

TEST_F(BST_test, height) {
    BST* root = NULL;
    EXPECT_EQ(0, root->height_recurisve(root));
    EXPECT_EQ(0, root->height_iterative(root));
    root = build_bst_iterative();
    EXPECT_EQ(3, root->height_recurisve(root));
    EXPECT_EQ(3, root->height_iterative(root));
}
TEST_F(BST_test, insertion) {
    // test for iterative insertion
    BST* root_recursive = build_bst_recursive();
    EXPECT_EQ(5, root_recursive->data);
    EXPECT_EQ(3, root_recursive->left->data);
    EXPECT_EQ(2, root_recursive->left->left->data);
    EXPECT_EQ(4, root_recursive->left->right->data);
    EXPECT_EQ(7, root_recursive->right->data);
    EXPECT_EQ(6, root_recursive->right->left->data);
    EXPECT_EQ(8, root_recursive->right->right->data);
    // test for iterative insertion
    BST* root_iterative = build_bst_iterative();
    EXPECT_EQ(5, root_iterative->data);
    EXPECT_EQ(3, root_iterative->left->data);
    EXPECT_EQ(2, root_iterative->left->left->data);
    EXPECT_EQ(4, root_iterative->left->right->data);
    EXPECT_EQ(7, root_iterative->right->data);
    EXPECT_EQ(6, root_iterative->right->left->data);
    EXPECT_EQ(8, root_iterative->right->right->data);
}

TEST_F(BST_test, search) {
    BST* root = build_bst_iterative();
    // test for recursive search
    EXPECT_EQ(5, root->search_recursive(root, 5)->data);
    EXPECT_EQ(8, root->search_recursive(root, 8)->data);
    EXPECT_EQ(NULL, root->search_recursive(root, 10));
    EXPECT_EQ(NULL, root->search_recursive(root, 1));
    // test for iterative search
    EXPECT_EQ(5, root->search_iterative(root, 5)->data);
    EXPECT_EQ(8, root->search_iterative(root, 8)->data);
    EXPECT_EQ(NULL, root->search_iterative(root, 10));
    EXPECT_EQ(NULL, root->search_iterative(root, 1));
}


