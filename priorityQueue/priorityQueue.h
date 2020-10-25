#include <iostream>
#include <vector>


using namespace std;
 
// Data structure for Min Heap
class PriorityQueue 
{

public:

    PriorityQueue() {};
    PriorityQueue(vector<int> pq)
    : priorityQueue(pq) {};


    // Public functions to access the priority queue and time complexity
    vector<int> getPriorityQueue() { return priorityQueue; }

    int getPriorityQueueSize() { return priorityQueue.size(); }

    bool pqEmpty() { return !priorityQueue.size(); }

    unsigned long int getTimeComplexity() { return timeComplexityCounter; }


    void buildPriorityQueue(vector<int> numbers){
        for(auto &num : numbers){
            push(num);
        }
    }


    int kSmallestElement(int k){
        for(size_t i = 1; i < k; i++){
            pop();
            //Increment counter - Linear time complexity
            timeComplexityCounter++;
        }

        return priorityQueue[0];
    }


    // insert key into the heap
    void push(int key) {
        // insert the new element to the end of the vector
        priorityQueue.push_back(key);
        
        // 1 Operation per push call - linear
        //timeComplexityCounter++;

        // get element index and call heapify-up procedure
        int index = priorityQueue.size() - 1;

        heapify_up(index);
    }

 
    // function to remove element with lowest priority (present at root)
    void pop() {
        // replace the root of the heap with the last element
        // of the vector
        priorityQueue[0] = priorityQueue.back();
        priorityQueue.pop_back();

        // 1 Operation per pop call - linear
        //timeComplexityCounter++;

        // call heapify-down on root node
        heapify_down(0);
    }


private:

    // vector to store heap elements
    vector<int> priorityQueue;

    unsigned long int timeComplexityCounter = 0;

    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void heapify_down(int i) {

        // get left and right child of node at index i
        int left = 2 * i + 1;
        int right = 2 * i + 2;
 
        int smallest = i;
 
        // compare priorityQueue[i] with its left and right child
        // and find smallest value
        if (left < priorityQueue.size() && priorityQueue[left] < priorityQueue[i])
            smallest = left;
 
        if (right < priorityQueue.size() && priorityQueue[right] < priorityQueue[smallest])
            smallest = right;
 
        // swap with child having lesser value
        if (smallest != i) {
            // 1 swap operation when child is less than its parent
            timeComplexityCounter++;
            swap(priorityQueue[i], priorityQueue[smallest]);
            //call heapify-down on the child
            heapify_down(smallest);
        }
    }

 
    // Recursive Heapify-up algorithm
    void heapify_up(int i) {

        int parent = (i - 1) / 2;

        // check if node at index i and its parent is not in order
        if (i && priorityQueue[parent] > priorityQueue[i]) 
        {
            // 1 swap operation when node and its parent are not in order
            timeComplexityCounter++;

            // swap the two nodes if heap is not in order
            swap(priorityQueue[i], priorityQueue[parent]);
            
            // call Heapify-up on the parent
            heapify_up(parent);
        }
    }

};
 
