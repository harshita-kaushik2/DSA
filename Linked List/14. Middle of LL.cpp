========> BRUTE FORCE : TRAVERSE ONCE AND CALCULATE LENGTH. THEN TRAVERSE TILL LENGTH/2 : temp = temp->next; return temp;

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

Node* middleNode(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < length / 2; i++)    temp = temp->next;
    return temp;
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

    Node* middle = middleNode(head);        //remember this line
    cout << "Middle Node: " << middle->val << endl;

    return 0;
}
