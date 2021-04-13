#include "BST.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <math.h>

/* Default constructor */
BST::BST() : data(0), left(NULL), right(NULL) {}

/* Parametrized constructor */
BST::BST(int data) : data(data), left(NULL), right(NULL) {}

/* Print white space given number */
void print_white_space(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << " ";
    }
}

/* Print the full structure of a bst */
void BST::print_bst(BST *root) {
    int height = height_iterative(root);
    std::queue<BST*> node_queue;
    node_queue.push(root);
    // get the maximum value of the bst
    int max_value = 0;
    BST* cur = root;
    while (cur != NULL) {
        max_value = cur->data;
        cur = cur->right;
    }
    // calcuate the digit of max value, set it as basic unit
    int unit = 0;
    while (max_value) {
        unit++;
        max_value /= 10;
    }
    // the number of units needed for the last level
    int max_unit_size = pow(2, height) * 2 - 1;
    for (int level = 1; level <= height; level++) {
        int level_node_num = node_queue.size();
        std::vector<int> level_node_value;
        // store current level nodes' data and next level nodes
        while(level_node_num--) {
            BST* cur_node = node_queue.front();
            node_queue.pop();
            if (cur_node != NULL) {
                level_node_value.push_back(cur_node->data);
                node_queue.push(cur_node->left);
                node_queue.push(cur_node->right);
            } else {
                level_node_value.push_back(-1);
                node_queue.push(NULL);
                node_queue.push(NULL);
            }
        }

        // calculate front white space and middle white space size
        int middle_space = max_unit_size / pow(2, level);
        int front_space = (max_unit_size - middle_space * (pow(2, level) - 1) - pow(2, level)) / pow(2, level);
        print_white_space(front_space * unit);
        if (level_node_value[0] != -1) {
            std::cout << level_node_value[0];
        } else {
            print_white_space(unit);
        }
        for (int i = 1; i < level_node_value.size(); i++) {
            print_white_space(middle_space * unit);
            if (level_node_value[i] != -1) {
                std::cout << level_node_value[i];
            } else {
                print_white_space(unit);
            }
        }
        std::cout << std::endl;
    }
}

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

/* Recursively find the height of a bst */
int BST::height_recurisve(BST* root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height_recurisve(root->left);
    int right_height = height_recurisve(root->right);
    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

/* Iteratively find the height of a bst */
int BST::height_iterative(BST* root) {
    // base condition
    if (root == NULL) {
        return 0;
    }
    // use queue to do level order traversal
    std::queue<BST*> level_queue;
    level_queue.push(root);
    int height = 0;
    while (1) {
        int cur_level_size = level_queue.size();
        if (cur_level_size == 0) {
            return height;
        }
        height++;
        // dequeue all nodes at current level
        // enqueue all nodes at the next level
        while (cur_level_size--) {
            BST* cur_node = level_queue.front();
            level_queue.pop();
            if (cur_node->left != NULL) {
                level_queue.push(cur_node->left);
            }
            if (cur_node->right != NULL) {
                level_queue.push(cur_node->right);
            }
        }
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

/* Recursively search a key */
BST* BST::search_recursive(BST* root, int data) {
    // base conditon: root is null or root contains data
    if (root == NULL || root->data == data) {
        return root;
    }
    // search for right subtree
    if (data > root->data) {
        return search_recursive(root->right, data);
    }
    // search for left subtree
    return search_recursive(root->left, data);
}

/* Iteratively search a key */
BST* BST::search_iterative(BST* root, int data) {
    // back up root
    BST* cur = root;
    while (cur != NULL) {
        // search right subtree
        if (data > cur->data) {
            cur = cur->right;
        } else if (data < cur->data) { // search left subtree
            cur = cur->left;
        } else { // found data
            return cur;
        }
    }
    return NULL;
}

/* Recursively delete a key */
BST* BST::delete_recursive(BST* root, int data) {
    // base case
    if (root == NULL) {
        return root;
    }
    // iterate over left subtree
    if (data < root->data) {
        root->left = delete_recursive(root->left, data);
    } else if (data > root->data) { // iterate over right subtree
        root->right = delete_recursive(root->right, data);
    } else { // delete the key
        // no children
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left == NULL) { // has only right child
            BST* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) { // has only left child
            BST* temp = root->left;
            free(root);
            return temp;
        }

        // has two children, replace it with the minimum value from right subtree, and delete the replaced node
        // find the minimum value from right subtree
        BST* min_node = root->right;
        while (min_node && min_node->left != NULL) {
            min_node = min_node->left;
        }
        // replace the value of the current node
        root->data = min_node->data;
        // delete the replaced node
        root->right = delete_recursive(root->right, min_node->data);
    }
    return root;
}
