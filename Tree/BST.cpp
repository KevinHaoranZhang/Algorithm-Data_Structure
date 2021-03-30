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

/* Recursively traverse a BST, Post-order */
void BST::postorder_recursive(BST* root) {
    if (root == NULL) {
        return;
    }
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    std::cout << root->data << std::endl;

}
/* Iteratively traverse a BST, in-order */
void BST::postorder_iterative(BST* root) {
    // using stack
    std::stack<BST*> node_stack;
    std::stack<BST*> output_stack;
    // backup root
    BST* cur = root;
    node_stack.push(cur);
    while (!node_stack.empty()) {
        cur = node_stack.top();
        node_stack.pop();
        output_stack.push(cur);
        if (cur->left != NULL) {
            node_stack.push(cur->left);
        }
        if (cur->right != NULL) {
            node_stack.push(cur->right);
        }
    }
    while (!output_stack.empty()) {
        std::cout << output_stack.top()->data << std::endl;
        output_stack.pop();
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

/* Iteratively insert a node */
BST* BST::insert_iterative(BST* root, int data) {
    // create a pointer to the new node
    BST* new_node = new BST(data);
    // backup root
    BST* cur = root;
    // store prev
    BST* prev = cur;
    while (cur != NULL) {
        prev = cur;
        // insertion on right subtree
        if (data > cur->data) {
            cur = cur->right;
        } else {
            // insertion on left subtree
            cur = cur->left;
        }
    }
    if (prev == NULL) {
        root = new_node;
    } else if (data > prev->data) {
        prev->right = new_node;
    } else {
        prev->left = new_node;
    }
    return root;
}
