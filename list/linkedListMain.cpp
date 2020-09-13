// Using array as stack
#include "LinkedList.h"

using namespace std;

int main(){
    
	// Linked list
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // print the linked list value
    head = one;
    while (head != NULL) {
        cout << "Head Value: " << head->value << endl;;
        head = head->next;
    }

    return 0;
}