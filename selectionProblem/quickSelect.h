#include <iostream>
#include <climits>
#include <vector>

using namespace std;

unsigned long int timeComplexityCounter = 0;


int quickSelect(vector<int>& numbers, int left, int right, int kthElement){

    // if left is equal to right we have reached the kth element
    while (left < right) {

        int leftPointer = left;
        int rightPointer = right;

        int center = numbers[(left + right) / 2];

        // stop if the reader and writer meets
        while (leftPointer < rightPointer) {

            if (numbers[leftPointer] >= center) { 
            // the value is larger than the pivot - put element at the end at right pointer and decrement
            swap(numbers[leftPointer], numbers[rightPointer]);
            timeComplexityCounter++;
            rightPointer--;
            } else { 
            // the value is smaller than the pivot - increment pointer and keep going
            leftPointer++;
            }
        }

        // if we incremented left pointer so its greater than pivot we need to decrement by one
        if (numbers[leftPointer] > center)
        leftPointer--;

        // the left pointer is on the end of the first k elements
        if (kthElement <= leftPointer) {
            right = leftPointer;
        } else {
            left = leftPointer + 1;
        }
    }

    return numbers[kthElement];

}