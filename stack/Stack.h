/*
C++ program to implement stack with array

Pros: Easy to implement. Memory is saved as pointers are not involved.
Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
*/

#include <bits/stdc++.h>  
using namespace std; 
  
#define MAX 1000 
  
class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 