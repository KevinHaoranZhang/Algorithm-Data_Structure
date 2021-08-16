#include "singly.h"
#include <iostream>
/* Default constructor */
Singly::Singly() : data(0), next(nullptr) {}
/* Parameterized constructor */
Singly::Singly(int data) : data(data), next(nullptr) {}

/* Utility functions */

/* Insertion: 3 methods */
void Singly::insert_head(Singly*& head_ref, int new_data) {
    Singly* new_node = new Singly(new_data);
    new_node->next = head_ref;
    head_ref = new_node;
}

void Singly::insert_tail(Singly*& head_ref, int new_data) {
    Singly* new_node = new Singly(new_data);
    // if linked list is empty, make head the new node
    if (head_ref == nullptr) {
        head_ref = new_node;
        return;
    }
    // iterate until the last node
    Singly* last = head_ref;
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

bool Singly::search_iterative(Singly* head, int key) {
    Singly* cur = head;
    while (cur != nullptr) {
        if (cur->data == key) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool Singly::search_recursive(Singly* head, int key) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == key) {
        return true;
    }
    return search_recursive(head->next, key);
}

void Singly::delete_iterative(Singly*& head_ref, int key) {
    Singly* cur = head_ref;
    Singly* prev = nullptr;

    // if head is the node to be deleted
    if (cur != nullptr && cur->data == key) {
        head_ref = cur->next;
        delete cur;;
        return;
    }

    // find the node with key and the node previous to it
    while (cur != nullptr && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    // if key not found, return
    if (cur == nullptr) {
        std::cout << "ERROR: KEY NOT FOUND" << std::endl;
        return;
    }

    // unlink from previous node
    prev->next = cur->next;
    delete cur;
}

void Singly::delete_recursive(Singly*& head_ref, int key) {
    if (head_ref == nullptr) {
        std::cout << "ERROR: KEY NOT FOUND" << std::endl;
        return;
    }
    if (head_ref->data == key) {
        Singly* temp = head_ref;
        head_ref = temp->next;
        delete temp;
        return;
    }
    delete_recursive(head_ref->next, key);
}