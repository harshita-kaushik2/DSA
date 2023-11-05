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
    Node* prev_p = nullptr;
    Node* current_p = head;
    Node* next_p;

    while (current_p) {
        next_p = current_p->next;
        current_p->next = prev_p;
        prev_p = current_p;
        current_p = next_p;
    }
    head = prev_p;
    return head;
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
