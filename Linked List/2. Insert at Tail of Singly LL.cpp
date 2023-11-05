#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->val << "-->";
        curr = curr->next;
    }
    cout << "null" << endl;
}

Node *InsertAtTail(int val, Node *head) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        // If the linked list is empty, make the new node the head and tail.
        head = newNode;
    } 
    else {
        // Otherwise, traverse to the end of the linked list and add the new node.
        Node *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
    return head;
}

int main() {
    Node *head = NULL;
    head = InsertAtTail(10, head);
    head = InsertAtTail(20, head);
    head = InsertAtTail(30, head);
    head = InsertAtTail(40, head);
    cout << "LinkedList before inserting 100 at end : " << endl;
    printList(head);
    head = InsertAtTail(100, head); // Change the value to 100
    cout << "LinkedList after inserting 100 at end : " << endl;
    printList(head);
    return 0;
}
