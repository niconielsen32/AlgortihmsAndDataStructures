// Priority Queue implementation in C++

#include <iostream>
#include <vector>
using namespace std;

// Function to swap position of two elements
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(vector<int> &tree, int i) {
  
  // Find the largest among root, left child and rigtree child
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < tree.size() && tree[l] > tree[largest])
    largest = l;
  if (r < tree.size() && tree[r] > tree[largest])
    largest = r;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&tree[i], &tree[largest]);
    heapify(tree, largest);
  }
}

// Function to insert an element into the tree
void insert(vector<int> &tree, int newNum) {

  if (tree.size() == 0) {
    tree.push_back(newNum);
  } else {
    tree.push_back(newNum);
    for (int i = tree.size() / 2 - 1; i >= 0; i--) {
      heapify(tree, i);
    }
  }
}

// Function to delete an element from the tree
void deleteNode(vector<int> &tree, int num) {

  int i;
  for (i = 0; i < tree.size(); i++) {
    if (num == tree[i])
      break;
  }
  swap(&tree[i], &tree[tree.size() - 1]);

  tree.pop_back();
  for (int i = tree.size() / 2 - 1; i >= 0; i--) {
    heapify(tree, i);
  }
}

// Print the tree
void printArray(vector<int> &tree) {
  for (int i = 0; i < tree.size(); ++i)
    cout << tree[i] << " ";
  cout << "\n";
}

// Main Function
int main() {
  vector<int> heapTree;

  // Insert the elemenst
  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  // Print Heap Tree
  cout << "Max-Heap array: ";
  printArray(heapTree);

  // Delette a node if the heap tree
  deleteNode(heapTree, 4);

  cout << "After deleting an element: ";

  // Print heap tree after deletion
  printArray(heapTree);
}