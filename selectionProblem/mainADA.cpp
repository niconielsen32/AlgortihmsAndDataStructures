#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <random>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Problem 1
#include "priorityQueue.h"
// Problem 2
#include "quickSelect.h"

using namespace std;


 

 



ofstream outputFile;
string filename = "testDataADA.csv";

vector<int> numberOfElements1 = {};
vector<int> numberOfOperations1 = {};

vector<double> numberOfOperations1Average = {};


vector<int> numberOfElements2 = {};
vector<int> numberOfOperations2 = {};
vector<double> numberOfOperations2Average = {};

vector<int> testNumbers = {};


 // Create priority queue - build it and test time complexity
PriorityQueue pq;
priority_queue<int> pqSTL;


// Variables for test
int numberOfTests = 20;

int numOfTestForAvg = 100;

int inputSize = 2;
int inputIncrease = 500;




int main()
{

    mt19937 gen(time(0));

    // Do several tests for problem 2
    for(int i = 0; i < numberOfTests; i++){

        for(int j = 0; j < numOfTestForAvg; j++){

            uniform_int_distribution<> dist(1,inputSize);

            testNumbers = {};


            for(size_t i = 1; i < inputSize; i++){
                testNumbers.push_back(i);
            }


            int randomK = dist(gen);

            //cout << "Random k:" << randomK << endl;

            // Shuffle the vector randomly
            shuffle(testNumbers.begin(), testNumbers.end(), gen);

            //cout << "Quick: " << endl;
            //for(auto &num : testNumbers){
              //  cout << num << " ";
            //}
            //cout << endl;


            // Problem 1
            for(auto &num : testNumbers){
                pqSTL.push(num);
            }

            pq.buildPriorityQueue(testNumbers);

            vector<int> numbers = pq.getPriorityQueue();

            numberOfOperations1.push_back(pq.getTimeComplexity());

            //cout << "Time Complexity - Number of Operations 1: " << pq.getTimeComplexity() << endl;

            int kthSmalletsPQ = pq.kSmallestElement(randomK);

            pq.resetObjectForTest();


            // Problem 2 - Quickselect
            int kthSmalletsQuick = quickSelect(testNumbers, 0, testNumbers.size()-1, randomK);

            cout << "Time Complexity - Number of Operations 2: " << timeComplexityCounter << endl;

            //cout << "k'smallets quickSelect: " << kthSmalletsQuick << endl;
            //cout << "PQ: " << kthSmalletsPQ << endl;

            numberOfOperations2.push_back(timeComplexityCounter);



            timeComplexityCounter = 0;
        }

        // Average test for problem 1
        int sum = 0;

        for(auto &i : numberOfOperations1){
            sum += i;
        }

        numberOfOperations1.clear();

        double avgOperations1 = sum/numOfTestForAvg;

        //cout << "sum 1: " << sum << " Inputsize 1: " << inputSize << " Avg 1: " << avgOperations1 << endl;

        numberOfOperations1Average.push_back(avgOperations1);


        // Average test for problem 2
        int sum2 = 0;

        for(auto &i : numberOfOperations2){
            sum2 += i;
        }

        numberOfOperations2.clear();

        double avgOperations2 = sum2/numOfTestForAvg;

        //cout << "sum 2: " << sum2 << " Inputsize 2: " << inputSize << " Avg 2: " << avgOperations2 << endl;

        numberOfOperations2Average.push_back(avgOperations2);

        numberOfElements1.push_back(inputSize);
        numberOfElements2.push_back(inputSize);

        inputSize += inputIncrease;

    }




        //cout << "Time Complexity - Number of Elements: " << pq.getPriorityQueueSize() << endl;
        //cout << "k'th smallest element: " << pq.kSmallestElement(11) << endl;
        //cout << "Time Complexity - Number of Operations: " << pq.getTimeComplexity() << endl;

        //cout << endl;


    
    outputFile.open(filename);


    // Output test results problem 1
    for(auto &num : numberOfElements1){
        //cout << num << " ";
        outputFile << num << ",";
    }

    cout << endl;
    outputFile << endl;

    for(auto &num : numberOfOperations1Average){
        //cout << num << " ";
        outputFile << num << ",";
    }

    cout << endl;
    outputFile << endl;

    // Output test results problem 1
    for(auto &num : numberOfElements1){
        //cout << num << " ";
        outputFile << num << ",";
    }

    outputFile << endl;
    for(auto &num : numberOfOperations2Average){
        //cout << num << " ";
        outputFile << num << ",";
    }

    cout << endl;


    outputFile.close();

    return 0;
}