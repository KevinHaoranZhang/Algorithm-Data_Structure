#include "BST.h"
#include <iostream>

/* Default constructor */
BST::BST() : data(0), left(NULL), right(NULL) {}

/* Parametrized constructor */
BST::BST(int data) : data(data), left(NULL), right(NULL) {}

/* Recursively traverse a BST, in-order */
void BST::inorder_recursive(BST* root) {
    if (root == NULL) {
        return;
    }
    inorder_recursive(root->left);
    std::cout << root->data << std::endl;
    inorder_recursive(root->right);
}

/* Recursively insert a node */
BST* BST::insert_recursive(BST* root, int data) {
    // if root is null, create a new root
    if (root == NULL) {
        return new BST(data);
    }
    // insert node
    if (data > root->data) {
        // process the right subtree
        root->right = insert_recursive(root->right, data);
    } else {
        // process the left subtree
        root->left = insert_recursive(root->left, data);
    }
    return root;
}