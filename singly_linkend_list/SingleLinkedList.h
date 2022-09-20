//
// Created by roman on 9/19/2022.
//

#ifndef DATA_STRUCTURE_C___SINGLELINKEDLIST_H
#define DATA_STRUCTURE_C___SINGLELINKEDLIST_H


#define DATA_STRACTURE_SINGLELINKEDLIST_H

#include <cassert>
#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Node {
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class finaly;

template<class T>
class SingleLinkedList {

private:
    Node<T> *head;
    Node<T> *tail;
    int length;


    void print_reverse(Node<T> *temp) {
        if (temp == NULL)
            return;
        print_reverse(temp->next);
        cout << temp->data << " ";


    }

    T get_by_index(Node<T> *temp, int index) {
        T data;
        while (index--) {
            data = temp->data;
            temp = temp->next;
        }
        return data;

    }

    int _search(Node<T> *temp, T data) {
        int index = 0;
        while (temp != NULL) {
            if (temp->data == data) {
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;

    }

    int _improvementSearch(Node<T> *temp, T data) {
        int index = 0;
        if (temp->data == data) {
            return index;
        } else {
            Node<T> *previous = nullptr;
            while (temp != NULL) {
                if (temp->next->data == data) {
                    previous = temp;
                    temp = temp->next;
                    swap(previous->data, temp->data);
                    return index--;
                }
                index++;
                temp = temp->next;
            }
            return -1;
        }
        return -1;
    }


public:
    SingleLinkedList() {
        this->head = NULL;
        this->tail = NULL;

        length = 0;
    }
    ~SingleLinkedList(){
        while (head){
            Node<T> cur = head->next;
            delete head;
            head = cur;
        }
    }


    void insert_end(T data) {
        Node<T> *item = new Node<T>(data);
        if (!head) {
            head = tail = item;
        } else {
            tail->next = item;
            tail = item;
        }
        length++;
    }

    void insert_front(T data) {
        Node<T> *item = new Node<T>(data);
        item->data = data;
        if (!head)
            head = tail = item;
        else {
            item->next = head;
            head = item;
        }
        length++;


    }
    void deleteFront (){
        head = head->next;
    }

    T get_end() {
        return tail->data;
    }

    T get_first() {
        return head->data;
    }

    T getByIndex(int index) {
        assert(index <= length && index > 0);
        get_by_index(head, index);

    }
    T getByIndexFromEnd(int index) {
        assert(index <= length && index > 0);
        return  get_by_index(head,length- index);

    }

    int get_size() {
        return length;
    }

    int search(T data) {
        return _search(head, data);
    }

    int improvementSearch(T data) {

        return _improvementSearch(head, data);


    }


    void print() {
        Node<T> *temp_node = head;

        while (temp_node != nullptr) {
            cout << temp_node->data << " ";
            temp_node = temp_node->next;
        }
        cout << "\n";
    }

    void printReverse() {
        /// wow wow wow
        print_reverse(head);
        cout << "\n";
    }


};


#endif //DATA_STRUCTURE_C___SINGLELINKEDLIST_H


