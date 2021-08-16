#ifndef LINKED_LIST_SINGLY_H
#define LINKED_LIST_SINGLY_H

class Singly {
public:
    /* Linked list node data structure */
    int data;
    Singly* next;

    /* Default constructor */
    Singly();
    /* Parameterized constructor */
    Singly(int data);

    /* Utility functions */

    /* Insertion: 3 methods */
    void insert_head(Singly*& head_ref, int new_data);
    void insert_tail(Singly*& head_ref, int new_data);
    void insert_after(Singly* prev_node, int new_data);

    /* Search: if found, return true; else, return false */

    /* Recursively search a key */
    bool search_recursive(Singly* head, int key);
    /* Iteratively search a key */
    bool search_iterative(Singly* head, int key);

    /* Delete: delete node with a given key */

    /* Recursively delete a key */
    void delete_recursive(Singly*& head_ref, int key);
    /* Iteratively delete a key */
    void delete_iterative(Singly*& head_ref, int key);
};

#endif //LINKED_LIST_SINGLY_H
