#include <iostream>
#include <vector>


using namespace std;
 
// Create own Priority Queue class as a min heap
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


    void buildPriorityQueue(const vector<int> &numbers){
        for(auto &num : numbers){
            // Push numbers from vector to create priority queue
            push(num);
        }
    }


    int kSmallestElement(int k){
        for(size_t i = 1; i < k; i++){
            pop();
            // Increment counter - Linear time complexity
            timeComplexityCounter++;
        }

        return priorityQueue[0];
    }


    // Push key into the priority queue
    void push(int key) {
        // Insert the new element to the end of the vector
        priorityQueue.push_back(key);
        
        // 1 Operation per push call - linear
        // timeComplexityCounter++;

        // Get element index and call heapify-up
        int index = priorityQueue.size() - 1;

        heapify_up(index);
    }

 
    // Function to remove element with lowest priority - root node
    void pop() {
        // Replace the root of the heap with the last element of the vector
        priorityQueue[0] = priorityQueue.back();
        priorityQueue.pop_back();

        // 1 Operation per pop call - linear
        // TimeComplexityCounter++;

        // Call heapify-down on root node
        heapify_down(0);
    }


private:

    // Vector to store min heap elements
    vector<int> priorityQueue;

    unsigned long int timeComplexityCounter = 0;

    // Recursive Heapify-down algorithm
    // Parent node and its two direct children out of order
    void heapify_down(int i) {

        // Get left and right child of parent node
        int left = 2 * i + 1;
        int right = 2 * i + 2;
 
        int smallest = i;
 
        // Compare parent node with its left and right child and find the smallest value
        if (left < priorityQueue.size() && priorityQueue[left] < priorityQueue[i])
            smallest = left;
 
        if (right < priorityQueue.size() && priorityQueue[right] < priorityQueue[smallest])
            smallest = right;
 
        // Swap with child having lesser value than parent
        if (smallest != i) {
            // 1 swap operation when child is less than its parent
            timeComplexityCounter++;
            swap(priorityQueue[i], priorityQueue[smallest]);
            // Call heapify-down on the child
            heapify_down(smallest);
        }
    }

 
    // Recursive Heapify-up algorithm
    void heapify_up(int i) {

        int parent = (i - 1) / 2;

        // Check if node at index i and its parent is not in order
        if (i && priorityQueue[parent] > priorityQueue[i]) 
        {
            // 1 swap operation when node and its parent are not in order
            timeComplexityCounter++;

            // Swap the two nodes if heap is not in order
            swap(priorityQueue[i], priorityQueue[parent]);
            
            // Call Heapify-up on the parent
            heapify_up(parent);
        }
    }

};
 
