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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);  // Initialize dummy node with a value
    Node* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;

        if (l1 != NULL) {
            sum = l1->val + sum;  // Corrected from l1->val to l1->num
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum = l2->val + sum;  // Corrected from l2->val to l2->num
            l2 = l2->next;
        }

        sum = sum + carry;
        carry = sum / 10;

        Node* node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create two linked lists for testing
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    // Call the addTwoNumbers function
    Node* result = addTwoNumbers(l1, l2);

    // Print the result
    cout << "Result: ";
    printLinkedList(result);

    return 0;
}
