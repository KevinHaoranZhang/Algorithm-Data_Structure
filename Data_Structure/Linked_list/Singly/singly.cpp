#include "Singly.h"

/* Default constructor */
Singly::Singly() : data(0), next(NULL) {}
/* Parameterized constructor */
Singly::Singly(int data) : data(data), next(NULL) {}

/* Utility functions */

/* Insertion: 3 methods */
void Singly::insert_head(Singly** head_ref, int new_data) {
    Singly* new_node = new Singly(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void Singly::insert_tail(Singly** head_ref, int new_data) {

}
void Singly::insert_after(Singly* prev_node, int new_data) {

}