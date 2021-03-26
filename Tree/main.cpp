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
    std::cout << "Recursive pre-order" << std::endl;
    b.preorder_recursive(root);
    std::cout << "Iterative pre-order" << std::endl;
    b.preorder_iterative(root);
    std::cout << "Recursive in-order" << std::endl;
    b.inorder_recursive(root);
    std::cout << "Iterative in-order" << std::endl;
    b.inorder_iterative(root);
    std::cout << "Recursive post-order" << std::endl;
    b.postorder_recursive(root);
    std::cout << "Iterative post-order" << std::endl;
    b.postorder_iterative(root);
    return 0;
}
