/*
C++ program to implement stack with linked list

Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
Cons: Requires extra memory due to involvement of pointers.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// A structure to represent a stack 
class StackNode { 
public: 
    int data; 
    StackNode* next; 
}; 
  
StackNode* newNode(int data) 
{ 
    StackNode* stackNode = new StackNode(); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(StackNode* root) 
{ 
    return !root; 
} 
  
void push(StackNode** root, int data) 
{ 
    StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    cout << data << " pushed to stack\n"; 
} 
  
int pop(StackNode** root) 
{ 
    if (isEmpty(*root)) 
        return INT_MIN; 
    StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 

int peek(StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->data; 
} 