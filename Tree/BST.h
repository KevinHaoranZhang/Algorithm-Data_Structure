#ifndef TREE_BST_H
#define TREE_BST_H
class BST {
public:
    /* Binary search tree node structure */
    int data;
    BST* left;
    BST* right;

    /* Default constructor */
    BST();
    /* Parametrized constructor */
    BST(int data);

    /* Utility functions */

    /* Traversal: pre-order, in-order, post-order */

    /* In-order: left, node, right. Print sorted data in ascending order */
    /* Recursively traverse a BST, in-order */
    void inorder_recursive(BST* root);
    /* Iteratively traverse a BST, in-order */
    void inorder_iterative(BST* root);

    /* Pre-order: node, left, right. Constructor sequence */
    /* Recursively traverse a BST, pre-order */
    void preorder_recursive(BST* root);
    /* Iteratively traverse a BST, pre-order */
    void preorder_iterative(BST* root);

    /* Post-order: left, right, node. Destructor sequence */
    /* Recursively traverse a BST, Post-order */
    void postorder_recursive(BST* root);
    /* Iteratively traverse a BST, in-order */
    void postorder_iterative(BST* root);

    /* Recursively insert a node */
    BST* insert_recursive(BST* root, int data);
};

#endif //TREE_BST_H
