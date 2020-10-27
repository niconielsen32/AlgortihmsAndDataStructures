#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <random>

// Problem 1
#include "priorityQueue.h"
// Problem 2
#include "quickSelect.h"

using namespace std;





int main()
{

    vector<int> testNumbers;

    for(size_t i = 1; i <= 200; i++){
        testNumbers.push_back(i);
    }


    // First create an instance of an engine
    random_device rnd_device;
    // Specify the engine and distribution
    mt19937 mersenne_engine {rnd_device()};

    // Shuffle the vector randomly
    shuffle(testNumbers.begin(), testNumbers.end(), mersenne_engine);

    cout << "Quick: " << endl;
    /*for(auto &num : testNumbers){
        cout << num << " ";
    }*/

    cout << endl;

    int kthSmallets = quickSelect(testNumbers, 0, testNumbers.size() - 1, 11);

    cout << "Time Complexity - Number of Operations: " << timeComplexityCounter << endl;

    cout << "k'smallets quickSelect: " << kthSmallets << endl;











    // Create priority queue - build it and test time complexity
    PriorityQueue pq;

    priority_queue<int> pqSTL;

    for(auto &num : testNumbers){
        pqSTL.push(num);
    }


    pq.buildPriorityQueue(testNumbers);

    vector<int> numbers = pq.getPriorityQueue();

    /*cout << "Class: " << endl;
    for(auto &num : numbers){
        cout << num << " ";
    }*/


    cout << "Time Complexity - Number of Elements: " << pq.getPriorityQueueSize() << endl;
    cout << "k'th smallest element: " << pq.kSmallestElement(11) << endl;
    cout << "Time Complexity - Number of Operations: " << pq.getTimeComplexity() << endl;

    cout << endl;
    
 
    return 0;
}