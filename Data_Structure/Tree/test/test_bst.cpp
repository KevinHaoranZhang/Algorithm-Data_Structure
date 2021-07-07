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
    root = bst.insert_iterative(root, 15);
    bst.insert_iterative(root, 13);
    bst.insert_iterative(root, 12);
    bst.insert_iterative(root, 10);
    bst.insert_iterative(root, 9);
    bst.insert_iterative(root, 11);
    bst.insert_iterative(root, 14);
    bst.insert_iterative(root, 20);
    bst.insert_iterative(root, 18);
    bst.insert_iterative(root, 22);
    bst.insert_iterative(root, 21);
    bst.insert_iterative(root, 23);
    return root;
}

BST* BST_test::build_bst_recursive() {
    BST bst, *root = NULL;
    root = bst.insert_recursive(root, 15);
    bst.insert_recursive(root, 13);
    bst.insert_recursive(root, 12);
    bst.insert_recursive(root, 10);
    bst.insert_recursive(root, 9);
    bst.insert_recursive(root, 11);
    bst.insert_recursive(root, 14);
    bst.insert_recursive(root, 20);
    bst.insert_recursive(root, 18);
    bst.insert_recursive(root, 22);
    bst.insert_recursive(root, 21);
    bst.insert_recursive(root, 23);
    return root;
}

TEST_F(BST_test, print) {
    BST* root = build_bst_iterative();
    root->print_bst(root);
}

TEST_F(BST_test, traversal) {
    BST* root = build_bst_iterative();
    std::cout << "Pre-order traversal, iterative" << std::endl;
    root->preorder_iterative(root);
    std::cout << "Pre-order traversal, recursive" << std::endl;
    root->preorder_recursive(root);
    std::cout << "In-order traversal, iterative" << std::endl;
    root->inorder_iterative(root);
    std::cout << "In-order traversal, recursive" << std::endl;
    root->inorder_recursive(root);
    std::cout << "Post-order traversal, iterative" << std::endl;
    root->postorder_iterative(root);
    std::cout << "Post-order traversal, recursive" << std::endl;
    root->postorder_recursive(root);
}

TEST_F(BST_test, height) {
    BST* root = NULL;
    EXPECT_EQ(0, root->height_recurisve(root));
    EXPECT_EQ(0, root->height_iterative(root));
    root = build_bst_iterative();
    EXPECT_EQ(5, root->height_recurisve(root));
    EXPECT_EQ(5, root->height_iterative(root));
}
TEST_F(BST_test, insertion) {
    // test for iterative insertion
    BST* root_recursive = build_bst_recursive();
    EXPECT_EQ(15, root_recursive->data);
    EXPECT_EQ(13, root_recursive->left->data);
    EXPECT_EQ(12, root_recursive->left->left->data);
    EXPECT_EQ(10, root_recursive->left->left->left->data);
    EXPECT_EQ(9, root_recursive->left->left->left->left->data);
    EXPECT_EQ(11, root_recursive->left->left->left->right->data);
    EXPECT_EQ(14, root_recursive->left->right->data);
    EXPECT_EQ(20, root_recursive->right->data);
    EXPECT_EQ(18, root_recursive->right->left->data);
    EXPECT_EQ(22, root_recursive->right->right->data);
    EXPECT_EQ(21, root_recursive->right->right->left->data);
    EXPECT_EQ(23, root_recursive->right->right->right->data);
    // test for iterative insertion
    BST* root_iterative = build_bst_iterative();
    EXPECT_EQ(15, root_iterative->data);
    EXPECT_EQ(13, root_iterative->left->data);
    EXPECT_EQ(12, root_iterative->left->left->data);
    EXPECT_EQ(10, root_iterative->left->left->left->data);
    EXPECT_EQ(9, root_iterative->left->left->left->left->data);
    EXPECT_EQ(11, root_iterative->left->left->left->right->data);
    EXPECT_EQ(14, root_iterative->left->right->data);
    EXPECT_EQ(20, root_iterative->right->data);
    EXPECT_EQ(18, root_iterative->right->left->data);
    EXPECT_EQ(22, root_iterative->right->right->data);
    EXPECT_EQ(21, root_iterative->right->right->left->data);
    EXPECT_EQ(23, root_iterative->right->right->right->data);
}

TEST_F(BST_test, search) {
    BST* root = build_bst_iterative();
    // test for recursive search
    EXPECT_EQ(12, root->search_recursive(root, 12)->data);
    EXPECT_EQ(9, root->search_recursive(root, 9)->data);
    EXPECT_EQ(NULL, root->search_recursive(root, 100));
    EXPECT_EQ(NULL, root->search_recursive(root, 1));
    // test for iterative search
    EXPECT_EQ(12, root->search_iterative(root, 12)->data);
    EXPECT_EQ(9, root->search_iterative(root, 9)->data);
    EXPECT_EQ(NULL, root->search_iterative(root, 100));
    EXPECT_EQ(NULL, root->search_iterative(root, 1));
}

TEST_F(BST_test, delete) {
    BST* root_recursive = build_bst_iterative();
    BST* root_iterative = build_bst_iterative();
    // test for recursive delete
    root_recursive->delete_recursive(root_recursive, 20);
    EXPECT_EQ(15, root_recursive->data);
    EXPECT_EQ(13, root_recursive->left->data);
    EXPECT_EQ(12, root_recursive->left->left->data);
    EXPECT_EQ(10, root_recursive->left->left->left->data);
    EXPECT_EQ(9, root_recursive->left->left->left->left->data);
    EXPECT_EQ(11, root_recursive->left->left->left->right->data);
    EXPECT_EQ(14, root_recursive->left->right->data);
    EXPECT_EQ(21, root_recursive->right->data);
    EXPECT_EQ(18, root_recursive->right->left->data);
    EXPECT_EQ(22, root_recursive->right->right->data);
    EXPECT_EQ(23, root_recursive->right->right->right->data);
    // test for recursive delete
    root_iterative->delete_iterative(root_iterative, 20);
    EXPECT_EQ(15, root_iterative->data);
    EXPECT_EQ(13, root_iterative->left->data);
    EXPECT_EQ(12, root_iterative->left->left->data);
    EXPECT_EQ(10, root_iterative->left->left->left->data);
    EXPECT_EQ(9, root_iterative->left->left->left->left->data);
    EXPECT_EQ(11, root_iterative->left->left->left->right->data);
    EXPECT_EQ(14, root_iterative->left->right->data);
    EXPECT_EQ(21, root_iterative->right->data);
    EXPECT_EQ(18, root_iterative->right->left->data);
    EXPECT_EQ(22, root_iterative->right->right->data);
    EXPECT_EQ(23, root_iterative->right->right->right->data);
}
