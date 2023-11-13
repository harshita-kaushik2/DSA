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

    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        if(curr==NULL) {
            head = prev;
            return;
        }
        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head, curr, prev);
        return head;
    }
};


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

    head = reverseLinkedList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
