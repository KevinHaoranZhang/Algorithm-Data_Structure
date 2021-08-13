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
    void insert_head(Singly** head_ref, int new_data);
    void insert_tail(Singly** head_ref, int new_data);
    void insert_after(Singly* prev_node, int new_data);

};

#endif //LINKED_LIST_SINGLY_H
