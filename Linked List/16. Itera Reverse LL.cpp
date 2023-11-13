#include <iostream>
using namespace std; 

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* reverseList(Node* head) {
    if(head==NULL || head->next == NULL)    return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr!=NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
