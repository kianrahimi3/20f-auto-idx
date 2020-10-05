//
// Created by kianr on 9/17/2020.
//

#ifndef INC_20F_AUTO_IDX_DSLIST_H
#define INC_20F_AUTO_IDX_DSLIST_H

#include <iostream>
using namespace std;


template<typename T>
//Node struct/class for use in the Linked List
struct Node {
    T item;
    Node<T> *next;
    Node<T> *previous;
};

//Linked list class
template<typename T>
class DSList {

private:

    Node<T> head;
    Node<T> tail;

public:
    //default constructor
    DSList() {

        head.next = &tail;
        tail.previous = &head;
        head.previous = nullptr;
        tail.next = nullptr;

    }

    //assignment operator
    DSList& operator=(const DSList& copy)
    {
        if(this == &copy)
            return *this;

        while (copy.head->next!=nullptr)
        {
            Node<T> *curr = copy.head->next;
            insertLast(curr->element);
            copy.head->next = curr->next;
        }

        return *this;
    }

    //destructor
    ~DSList() {

    }

    // Returns the head of the list (1st item)
    Node<T>* front() {
        return head.next;
    }

    //Returns the tail in the list (last item)
    Node<T>* end() {
        return &tail;
    }

    // Adds a new item at the end of the list
    void push_back(T item) {
        insertAfter(*tail.previous, item);
    }

    //Adds item as the new head of the list
    void addAsHead(T item) {
        insertAfter(head, item);
    }

    //remove an item at a specific index
    void removeIndex(int index) {
        Node<T> *node = getNode(index);
        if (node != nullptr) {
            removeNode(node);
        }
    }

    // insert item at a specific index
    void insertNodeAt(int index, T item) {
        Node<T> *node = getNode(index);
        if (node != nullptr) {
            insertAfter(*node, item);
        }
    }

    // returns the node at a specific index
    Node<T> *getNode(int index) {
        Node<T> *node = front();
        for (int i = 0; i < index && node != end(); i++) {
            node = node->next;
        }
        if (node == end()) {
            return nullptr;
        }
        return node;
    }

    // removes a node
    void removeNode(Node<T> *node) {
        node->next->previous = node->previous;
        node->previous->next = node->next;
        delete node;
    }

    //insert a node after another specific node
    void insertAfter(Node<T> &after, T item) {
        Node<T> *node = new Node<T>();
        node->item = item;
        node->previous = &after;
        node->next = after.next;
        after.next->previous = node;
        after.next = node;
    }
};





#endif //INC_20F_AUTO_IDX_DSLIST_H
