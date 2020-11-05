#include <iostream>
#include <climits>
#include <vector>


using namespace std;
unsigned long int timeComplexityCounter = 0;


int median3(vector<int> vec, int left, int right){

    int center = (left + right) / 2;

    if(vec[center] < vec[left]){
        swap(vec[left], vec[center]);
    }
    if(vec[right] < vec[left]){
        swap(vec[left], vec[right]);
    }
    if(vec[right] < vec[center]){
        swap(vec[center], vec[right]);
    }

    swap(vec[center], vec[right - 1]);

    return vec[right - 1];
}


int quickSelect(vector<int>& numbers, int left, int right, int kthElement){

    // When left is equal to right we are at the kth element
    while (left < right) {

        int leftPointer = left;
        int rightPointer = right;

        int pivot = median3(numbers, left, right);

        // Stop if the two pointers meet each other
        while (leftPointer < rightPointer) {

            if (numbers[leftPointer] >= pivot) { 
            // The value is larger than the pivot - put element at the end at right pointer and decrement
            swap(numbers[leftPointer], numbers[rightPointer]);
            timeComplexityCounter++;
            rightPointer--;
            } else { 
            // the value is smaller than the pivot - increment pointer and keep going
            leftPointer++;
            }
        }

        // if we incremented left pointer so its greater than pivot we need to decrement by one
        if (numbers[leftPointer] > pivot)
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