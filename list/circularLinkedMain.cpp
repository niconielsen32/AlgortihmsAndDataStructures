// Using array as stack
#include "doublyLinkedList.h"

using namespace std;

int main(){
    
	// Doubly Linked list

    /* Initialize nodes */
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();

    /* Assign data values */
    one->value = 1;
    two->value = 2;
    three->value = 3;

    /* Connect nodes */
    one->next = two;
    two->next = three;
    three->next = one;

    /* Save address of first node in head */
    head = one;

    return 0;
}