=============>> APPROACH 1 : USING EXTRA SPACE

#include <bits/stdc++.h>
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

bool isPalindrome(Node* head) {
    vector<int> arr;
    while (head != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }
    for (int i = 0; i < arr.size() / 2; i++)
        if (arr[i] != arr[arr.size() - i - 1]) return false;
    return true;
}

void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return;
}

int main() {
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 5);
    isPalindrome(head) ? cout << "True" : cout << "False";
    return 0;
}

===========>> APPROACH 2 : OPTIMIZED

#include <bits/stdc++.h>
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

Node* reverse(Node* ptr) {
    Node* pre = NULL;
    Node* nex = NULL;
    while (ptr != NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    Node* dummy = head;

    while (slow != NULL) {
        if (dummy->val != slow->val) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

void insertNode(Node*& head, int val) {  // Pass head by reference
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return;
}

int main() {
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 8);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 5);
    isPalindrome(head) ? cout << "True" : cout << "False";
    return 0;
}
