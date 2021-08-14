#include "singly.h"
#include <iostream>
/* Default constructor */
Singly::Singly() : data(0), next(nullptr) {}
/* Parameterized constructor */
Singly::Singly(int data) : data(data), next(nullptr) {}

/* Utility functions */

/* Insertion: 3 methods */
void Singly::insert_head(Singly** head_ref, int new_data) {
    Singly* new_node = new Singly(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void Singly::insert_tail(Singly** head_ref, int new_data) {
    Singly* new_node = new Singly(new_data);
    // if linked list is empty, make head the new node
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    // iterate until the last node
    Singly* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    // change the last node to new node
    last->next = new_node;
}
void Singly::insert_after(Singly* prev_node, int new_data) {
    if (prev_node == nullptr) {
        return;
    }
    Singly* new_node = new Singly(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}