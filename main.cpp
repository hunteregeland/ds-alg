#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

node* head = NULL;
node* current = NULL;
node* previous = NULL;

node* rev_head = NULL;
node* rev_current = NULL;
node* rev_previous = NULL;

int main() {
        // create list of five nodes
        head = new node; // start with initializing head node with no values
        current = head; // set current node to head for beginning of the list
        for (int i=0; i<5; i++) { // i-long list
            current->data = i+1; // set the value of the node
            current->next = new node; // create a new address for the next node and link it
            current->prev = previous; // link to the previous node
            // now we are linked on both sides, previous and next
            
            previous = current; // set the previous pointer to point at the current node so it can be referenced in next iteration
            current = current->next; // set the current pointer to the next address created above to iterate
        }

        // last node will have invalid data, so we need to remove it
        delete previous->next; // delete the actual address
        previous->next = NULL; // set the previous node's next address to NULL
        
        // print list
        current = head; // set current back to the beginning of the list so that we can print the whole thing
        while (current != NULL) { // until the node is NULL, so to the last node
            cout << "Node: " << current << ", Data: " << current->data << ", Next: " << current->next << ", Prev: " << current->prev << endl;
            current = current->next; // set the current pointer to the next address created above to iterate
        }
        current = head; // reset the current node to the beginning of list

        // get current to the last node of the normal list to iterate backwards
        while (current->next != NULL) {
            current = current->next;
        }

        // fill reverse list
        rev_head = new node; // set head of reverse list to a new node
        rev_current = rev_head; // set current of reverse to the head
        while (current != NULL) {
            rev_current->data = current->data; // set the value of the node
            rev_current->next = new node; // create a new address for the next node and link it
            rev_current->prev = rev_previous; // link to the previous node
            // now we are linked on both sides, previous and next
            
            // iterate reverse list forwards
            rev_previous = rev_current; // set the previous pointer to point at the current node so it can be referenced in next iteration
            rev_current = rev_current->next; // set the current pointer to the next address created above to iterate

            // iterate the normal list backwards
            current = current->prev;
        }

        // last node will have invalid data, so we need to remove it
        delete rev_previous->next; // delete the actual address
        rev_previous->next = NULL; // set the previous node's next address to NULL
        
        current = head; // reset normal current pointer
        rev_current = rev_head; // set rev_current back to the beginning of the reverse list so that we can print the whole thing
        

        // print reversed list
        std::cout << endl;
        while (rev_current != NULL) { // until the node is NULL, so to the last node
            cout << "Node: " << rev_current << ", Data: " << rev_current->data << ", Next: " << rev_current->next << ", Prev: " << rev_current->prev << endl;
            rev_current = rev_current->next; // set the current pointer to the next address created above to iterate
        }
        rev_current = head; // reset the current node to the beginning of list


        // FREE MEMORY
        current = head; // set the current node back to beginning of list
        while (current != NULL) { // until the node is NULL, so to the last node
            node* temp = current; // create a temp node and set it equal to the current node before it iterates
            current = current->next; // iterate the current node
            delete temp; // delete each memory address as it goes through after it iterates
        }

        return 0;
}