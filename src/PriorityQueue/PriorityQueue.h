#ifndef SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H
#define SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H

#include <list>
#include "../../src/MaxHeap/MaxHeap.cpp"

template <typename T>
class PriorityQueue {
public:

    PriorityQueue()=default;

    ~PriorityQueue()= default;
    /**
     * inserts map x into the priority queue
     * @param x the int, value map to be inserted
     */
    void Insert(T x);

    /**
     * returns a copy of the key-value tuple that has the largest key in the priority queue
     * @return a key-value pair representing the largest key in the queue
     */
    T Maximum();

    /**
     * removes the record from the priority queue and returns the key-value tuple that is with the largest key
     * @return a map representing the key-value map with the largest key
     */
    T Extract_Max();

    /**
     * increases the value of the key located at position 'position' in the queue; new_key is required to be greater than the key already stored at location 'position'
     * @param position the position in the queue that will be changed
     * @param new_key the value that will be added
     */
    void Increase_Key(int position, T new_key);

    /**
     * Returns the size of the queue
     * @return the size of the queue
     */
    int getSize(){
        return maxHeap->getSize();
    }
private:

    MaxHeap<T>* maxHeap = new MaxHeap<T>();

};




#endif //SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_PRIORITYQUEUE_H
