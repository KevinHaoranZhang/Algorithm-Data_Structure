#ifndef TREE_BST_H
#define TREE_BST_H
class BST {
private:
    /* Binary search tree node structure */
    int data;
    BST* left;
    BST* right;
public:
    /* Default constructor */
    BST();
    /* Parametrized constructor */
    BST(int data);

    /* Utility functions */
    /* Recursively traverse a BST, in-order */
    void inorder_recursive(BST* root);
    /* Recursively insert a node */
    BST* insert_recursive(BST* root, int data);
};

#endif //TREE_BST_H