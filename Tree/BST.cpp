#include "BST.h"
#include <iostream>
#include <stack>

/* Default constructor */
BST::BST() : data(0), left(NULL), right(NULL) {}

/* Parametrized constructor */
BST::BST(int data) : data(data), left(NULL), right(NULL) {}

/* Recursively traverse a BST, pre-order */
void BST::preorder_recursive(BST* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->data << std::endl;
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

/* Iteratively traverse a BST, pre-order */
void BST::preorder_iterative(BST* root) {
    // base case
    if (root == NULL) {
        return;
    }
    // using stack
    std::stack <BST*> node_stack;
    // backup root
    node_stack.push(root);

    while (!node_stack.empty()) {
        BST* node_stack_top = node_stack.top();
        std::cout << node_stack_top->data << std::endl;
        node_stack.pop();
        // push right child before left child since stack is FILO
        if (node_stack_top->right != NULL) {
            node_stack.push(node_stack_top->right);
        }
        if (node_stack_top->left != NULL) {
            node_stack.push((node_stack_top->left));
        }
    }
}

/* Recursively traverse a BST, in-order */
void BST::inorder_recursive(BST* root) {
    if (root == NULL) {
        return;
    }
    inorder_recursive(root->left);
    std::cout << root->data << std::endl;
    inorder_recursive(root->right);
}

/* Iteratively traverse a BST, in-order */
void BST::inorder_iterative(BST* root) {
    // using stack
    std::stack <BST*> node_stack;
    // backup root
    BST* cur = root;
    // in-order traversal
    while (cur != NULL || !node_stack.empty()) {
        // iterate through left subtree
        while (cur != NULL) {
            node_stack.push(cur);
            cur = cur->left;
        }
        // left subtree done, print node
        cur = node_stack.top();
        std::cout << cur->data << std::endl;
        node_stack.pop();
        // iterate through right subtree
        cur = cur->right;
    }
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

/* Recursively traverse a BST, Post-order */
void BST::Postorder_recursive(BST* root) {

}
/* Iteratively traverse a BST, in-order */
void BST::Postorder_iterative(BST* root) {

}
