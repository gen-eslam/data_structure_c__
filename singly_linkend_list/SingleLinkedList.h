//
// Created by roman on 9/19/2022.
//

#ifndef DATA_STRACTURE_SINGLELINKEDLIST_H
#define DATA_STRACTURE_SINGLELINKEDLIST_H

#include <cassert>
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
    }
};

template<class T>
class SingleLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;


public:
     SingleLinkedList() {
        this->head = NULL;
         this->tail = NULL;
        length = 0;
    }

    void insert_end(T data) {
        Node item = new Node(data);
        item->data = data;
        if (!head) {
            head = tail = item;
        } else {
            tail->next = item;
            tail = item;
        }
        length++;
    }

    void insert_front(T data) {
        Node item = new Node(data);
        if (!head)
            head = tail = item;
        else {
            item->next = head;
            head = item;
        }
        length++;


    }

    T get_end() {
        return tail->data;
    }

    T get_first() {
        return head->data;
    }

    void print() {
        Node temp_node = head;
        while (temp_node != nullptr) {
            cout << temp_node->data << " ";
            temp_node = temp_node->next;
        }
        cout << "\n";
    }


};


#endif //DATA_STRACTURE_SINGLELINKEDLIST_H
