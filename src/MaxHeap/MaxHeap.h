//
// Created by xavier on 3/12/24.
//

#ifndef SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_MAXHEAP_H
#define SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_MAXHEAP_H

#include <string>

template <typename T>
class MaxHeap{
    public:
    /**
     * Creates a MaxHeap
     * @param a vector that's passed in to be created
     * @param s size of the vector
     */
    MaxHeap(T* a, int s);

    /**
     * Creates a MaxHeap
     */
    MaxHeap();

    /**
     * Default Deconstructor
     */
    ~MaxHeap()=default;

    /**
     * Turns the heap into an vector string
     * @return a string representing the heap
     */
    std::string toString();

    /**
     * The size of the heap
     * @return an integer representing the size of the heap
     */
    int getSize();

    /**
     * Runs heap sort on the internal vector
     * returning an vector in ascending order
     */
    void Heapsort();

    /**
     * Builds a Max Heap out of the internal vector
     */
    void Build_Max_Heap();

    /**
     * Returns the Highest value in the vector
     * @return the Highest value in the vector
     */
    T peekAtRoot();

    /**
     * Performs Max Heapify starting at the index i
     * @param i the index to start performing max heapify at
     */
     void Max_Heapify(int i);

     /**
      * inserts a value into the max heap
      * @param i the value to be inserted
      */
     void insert(T i);

    /**
    * Removes and returns the value at the root
    * @return the value at root
    * @throws out_of_range
    */
     T retrieveAndRemoveRoot();

    /**
    * Finds a value within the heap and returns its index
    * @param i the value to find
    * @return the index of the value
    */
    int find(T i);

    /**
    * Returns the value in the heap vector that was at index i
    * @param i the index the value exists in
    * @return the value
    */
    int valueAt(int i);

    /**
     * TODO Write tests
     * Removes the value at index i and inserts newval into the heap
     * @param i the index being removed
     * @param newval the value being inserted into the heap
     */
     void replaceAt(int i, T newval);


private:
    int size{};
    int heap_size{};
    std::vector<T> vector;

    static void swap(MaxHeap* m, int index1, int index2){
        T t = m->vector[index1];
        m->vector[index1] = m->vector[index2];
        m->vector[index2] = t;
    }

    static int left(int i){
        return 2*i+1;
    }

    static int right(int i){
        return 2*(i+1);
    }

    /**
     * Removes the item at index i
     * @param i index where an item is being removed
     */
    void remove(int i){
        if(this->size == 0) throw std::out_of_range("Size of heap is 0");
        int t = i;
        this->vector[i] = this->getArrayValue(this->size - 1);
        Max_Heapify(i);
        vector.pop_back();
        this->size--;
        this->heap_size--;
    }

    static int parent(int i){
        if (i % 2 == 0)  // right
            return (i - 2) / 2;
        else  // left
            return (i - 1) / 2;
    }

    static std::string heap_to_String(MaxHeap* h){
        std::string s;
        s+="[";
        for(int i = 0; i < h->size; i++ ){
            s+=std::to_string(h->getArrayValue(i));
            if(i!=h->size-1){
                s+=",";
            }
        }
        s+="]";
        return s;
    }

    /**
     * Gets the internal vector of the datastructure
     * @return the internal integer vector
     */
    std::vector<T> getArray(){
        return vector;
    }

    /**
     * Gets a specific value from the vector
     * @param i the index value to get from
     * @return the value
     */
    T getArrayValue(int i){
        if(size == 0) throw std::out_of_range ("Array is of size 0");
        return getArray()[i];
    }

    /**
     * Sets the vector
     * @param s the new vector
     * @param n the new vector size
     */
    void setArray(T* s, int n){
        this->vector.clear();
        for(int i = 0; i < n; i ++){
            vector.push_back(s[i]);
        }
    }

    /**
     * Sets the size of the vector
     * @param s the new size of the vector
     */
    void setSize(int s){
        this->size = s;
    }

    /**
     * Sets the size of the heap
     * @param s the new size of the heap
     */
    void setHeap_Size(int s){
        this->heap_size = s;
    }

    /**
     * Gets the heap size
     * @return the size of the heap
     */
    int getHeap_Size(){
        return this->heap_size;
    }
};

#endif //SP24_SE_CSCI_C455_XAVBEAT03_HOMEWORK_ASSIGNMENT_4_MAXHEAP_H
