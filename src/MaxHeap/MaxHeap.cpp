#include <iostream>
#include <vector>

#include "MaxHeap.h"


//TODO Make MaxHeap Generic
//TODO Rewrite .h file and adjust .cpp file

    template <typename T>
    MaxHeap<T>::MaxHeap(T* a, int s){
        this->size = s;
        this->heap_size = s;
        for(int i = 0; i < s; i ++){
            vector.push_back(a[i]);
        }
    }

    template <typename T>
    MaxHeap<T>::MaxHeap(){
        this->size = 0;
        this->heap_size = 0;
    }


    template <typename T>
    std::string MaxHeap<T>::toString(){
        return heap_to_String(this);
    }

    template <typename T>
    int MaxHeap<T>::getSize(){
        return this->size;
    }

    template <typename T>
    void MaxHeap<T>::Heapsort(){
        Build_Max_Heap();
        for(int i = this->size-1; i > 0; i--){
            swap(this, 0, i);
            this->heap_size--;
            Max_Heapify(0);
        }
    }

    template <typename T>
    void MaxHeap<T>::Build_Max_Heap(){
        this->heap_size = this->size;
        for(int i = this->size >> 1; i > -1; i--){
            Max_Heapify(i);
        }
    }

    template <typename T>
    T MaxHeap<T>::peekAtRoot(){
        return vector.at(0);
    }

    template <typename T>
    void MaxHeap<T>::Max_Heapify(int i){
        if(this->size == 0) {
            throw std::out_of_range ("Index is outside of heap size");
        }
        int l = left(i);
        int r = right(i);
        int largest;
        if(l <= this->heap_size-1 && getArrayValue(l) > getArrayValue(i)){
            largest = l;
        } else {
            largest = i;
        }

        if(r <= this->heap_size-1 && getArrayValue(r) > getArrayValue(largest)){
            largest = r;
        }

        if (largest != i){
            swap(this, i, largest);
            Max_Heapify(largest);
        }

    }

    template <typename T>
    void MaxHeap<T>::insert(T i){
        vector.push_back(i);
        size++;
        int k = size-1;
        while(k != 0 && getArrayValue(parent(k)) < i){
            swap(this, k, parent(k));
            k = parent(k);
        }
        this->heap_size++;
    }

    template <typename T>
    T MaxHeap<T>::retrieveAndRemoveRoot(){
        if(this->size == 0) throw std::out_of_range("Size of heap is 0");
        T i = this->vector[0];
        int t = 0;
        this->vector[0] = this->getArrayValue(this->size - 1);
        Max_Heapify(0);
        vector.pop_back();
        this->size--;
        this->heap_size--;
        return i;
    }

    template <typename T>
    int MaxHeap<T>::find(T i){
        int temp = 0;

        while (getArrayValue(temp) != i && temp < this->size){
            temp++;
        }

        if(temp==this->size) return -1;
        else return temp;
    }

    template <typename T>
    int MaxHeap<T>::valueAt(int i){
        return getArrayValue(i);
    }

    template <typename T>
    void MaxHeap<T>::replaceAt(int i, T newval){
        remove(i);
        insert(newval);
    }






