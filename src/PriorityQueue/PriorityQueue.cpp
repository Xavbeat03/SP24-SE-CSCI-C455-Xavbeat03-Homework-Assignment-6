#include "PriorityQueue.h"

template<typename T>
T PriorityQueue<T>::Maximum() {
    return maxHeap->peekAtRoot();
}

template<typename T>
void PriorityQueue<T>::Insert(T x) {
    maxHeap->insert(x);
}

template<typename T>
T PriorityQueue<T>::Extract_Max() {
    if(this->maxHeap->getSize() == 0) throw std::out_of_range("Cannot extract nonexistent value.");
    return maxHeap->retrieveAndRemoveRoot();
}

template<typename T>
void PriorityQueue<T>::Increase_Key(int position, T new_key) {
    if(this->maxHeap->getSize() == 0)
        throw std::out_of_range ("Position is outside of queue");
    else if(position >= this->maxHeap->getSize())
        throw std::out_of_range ("Position is outside of queue");
    else if(position < 0)
        throw std::out_of_range ("Position is outside of queue");
    else {
        if (maxHeap->valueAt(position) < new_key) {
            maxHeap->replaceAt(position, new_key);
        }
    }
}

