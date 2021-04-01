#include <iostream>
#include "BST.h"

int main() {
    BST b, *root = NULL;
    // recursive insertion
//    root = b.insert_recursive(root, 50);
//    b.insert_recursive(root, 30);
//    b.insert_recursive(root, 20);
//    b.insert_recursive(root, 40);
//    b.insert_recursive(root, 70);
//    b.insert_recursive(root, 60);
//    b.insert_recursive(root, 80);

    // iterative insertion
    root = b.insert_iterative(root, 50);
    b.insert_iterative(root, 30);
    b.insert_iterative(root, 20);
    b.insert_iterative(root, 40);
    b.insert_iterative(root, 70);
    b.insert_iterative(root, 60);
    b.insert_iterative(root, 80);
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
    std::cout << "Recursively search for existing value 50" << std::endl;
    if (b.search_recursive(root, 50) != NULL) {
        std::cout << "Found 50" << std::endl;
    }
    std::cout << "Recursively search for non-existing value 100" << std::endl;
    if (b.search_recursive(root, 100) == NULL) {
        std::cout << "Not Found 100" << std::endl;
    }
    std::cout << "Iteratively search for existing value 50" << std::endl;
    if (b.search_iterative(root, 50) != NULL) {
        std::cout << "Found 50" << std::endl;
    }
    std::cout << "Iteratively search for non-existing value 100" << std::endl;
    if (b.search_iterative(root, 100) == NULL) {
        std::cout << "Not Found 100" << std::endl;
    }
    return 0;
}
