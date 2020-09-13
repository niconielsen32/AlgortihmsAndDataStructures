// Using array as stack
#include "Stack.h"
#include "StackLinkedList.h"

using namespace std;

int main(){
	//cout << "Using Array for Stack" << endl;

    class Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3);
    int elementPopped = s.pop(); 

    //cout << elementPopped << " Popped from stack" << endl; 

    // Using linked list as stack
    cout << endl;
    //cout << "Using Linked List for Stack" << endl;

    StackNode* root = NULL; 
  
    push(&root, 1); 
    push(&root, 2); 
    push(&root, 3); 
  
    //cout << pop(&root) << " popped from stack" << endl; 
  
    //cout << "Top element is " << peek(root) << endl; 

    queue<int> builtInQueue;

    builtInQueue.push(1);
    builtInQueue.push(2);
    builtInQueue.push(3);

    builtInQueue.pop();

    //cout << builtInQueue.back() << " top element on stack" << endl;

    return 0;
}