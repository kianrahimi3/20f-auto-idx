//
// Created by kianr on 9/17/2020.
//

#ifndef INC_20F_AUTO_IDX_DSLIST_H
#define INC_20F_AUTO_IDX_DSLIST_H

#include <iostream>
using namespace std;



template <class T>
class DSList {
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node() {
            next = nullptr;
            prev = nullptr;
        }
        Node(T data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void push_back(T data);
    void push_front(T data);
    T& operator[] (int);


    //overloaded << operator to print the list
    friend ostream &operator << (ostream &output,  DSList<T>& list)
    {
        Node* temp = list.head;
        cout << "Printing the list: " << endl;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return output;
    }

};

template <class T>
void DSList<T>::push_back(T data) {
    Node* curr = new Node(data);
    if(head == nullptr) {
        head = curr;
        tail = curr;
    }
    else {
        tail->next = curr;
        curr->prev = tail;
    }
    tail = curr;
}

template <class T>
void DSList<T>::push_front(T data) {
    Node* curr = new Node(data);
    if(head == nullptr) {
        head = curr;
        tail = curr;
    }
    else {
        head->prev = curr;
        curr->next = head;
        head = curr;
    }
}

template <class T>
T & DSList<T>::operator[](int val) {
    Node *temp = head;
    for(int i = 0; i < val; i++) {
        temp = temp->next;
    }
    return temp->data;
}





#endif //INC_20F_AUTO_IDX_DSLIST_H
