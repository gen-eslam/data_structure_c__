//
// Created by roman on 9/19/2022.
//

#ifndef DATA_STRUCTURE_C___VECTOR_H
#define DATA_STRUCTURE_C___VECTOR_H





#include <cassert>
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Vector {
private:
    T *arr = nullptr;
    int size = 0;
    int capacity;

    void extend_capacity() {
        capacity *= 2;
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        deleteCopy(arr, arr2);


    }

    void deleteCopy(int *arr, int *arr2) {
        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(int size) {
        this->size = size;
        if (size < 0)
            size = 1;
        capacity = size * 2;
        arr = new int[capacity];
    }


    void push_back(T value) {

        if (size == capacity)
            extend_capacity();
        arr[size] = value;
        size = size + 1;


    }

    void insert(int index, T value) {
        if (size == capacity)
            extend_capacity();
        for (int p = size - 1; p >= index; --p)
            arr[p + 1] = arr[p];
        arr[index] = value;
        size++;

    }
    int pop(int index){
        T result = arr[index];
        assert(index>=0 && index<size);
        for(int i=index;i<size;i++)
            arr[i]=arr[i+1];
        size--;
        return result;
    }

    void right_rotate(){
        int temp = arr[size-1];
        for(int i=size-1;i>0;i--)
            arr[i]=arr[i-1];
        arr[0]= temp;
    }
    void right_rotate(int times){
        assert(times>0);
        while(times--){
            right_rotate();
        }
    }
    void left_rotate(){

        int temp = arr[0];
        for(int i=1;i<size;i++)
            arr[i-1]=arr[i];
        arr[size-1]= temp;
    }

    void left_rotate(int times){
        assert(times>0);
        while(times--){
            left_rotate();
        }
    }
    int find_transposition(T value){
        int found = find(value);
        if (found =-1)
            return -1;
        T temp = arr[found-1];
        arr[found-1]=arr[found];
        arr[found]= temp;
        return found-1;
    }



    void set(int index, T value) {
        assert(0 <= index && index < size);
        arr[index] = value;
    }

    int find(T value) {
        for (int i = 0; i < size; i++)
            if (arr[i] == value)
                return i;
        return -1;

    }

    int get_capacity() {
        return capacity;
    }

    int get(int index) {
        assert(0 <= index && index < size);
        return arr[index];
    }

    int get_front() {
        return arr[0];
    }

    int get_back() {
        return arr[size - 1];
    }

    int get_size() {
        return size;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }
};


/// notes
/*
 *  1 ->  this ->size = size =====>  vector(int size) : size(size){ your code }
 *
 *
 *
 * */


#endif //DATA_STRUCTURE_C___VECTOR_H
