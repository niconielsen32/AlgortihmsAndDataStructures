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
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    /* Save address of first node in head */
    head = one;

    // print the linked list value
    while (head != NULL) {
        cout << "Head Value: " << head->value << endl;;
        head = head->next;
    }

    return 0;
}