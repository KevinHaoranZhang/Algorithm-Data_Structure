#include <iostream>
#include "BST.h"

int main() {
    BST b, *root = NULL;
    root = b.insert_recursive(root, 50);
    b.insert_recursive(root, 30);
    b.insert_recursive(root, 20);
    b.insert_recursive(root, 40);
    b.insert_recursive(root, 70);
    b.insert_recursive(root, 60);
    b.insert_recursive(root, 80);

    b.inorder_recursive(root);
    return 0;
}