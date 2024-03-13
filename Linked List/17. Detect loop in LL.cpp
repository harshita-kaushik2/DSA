APPROACH 1 : USING EXTRA SPACE AS HASHMAP
#include <iostream>
#include <unordered_set>
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

bool cycleDetect(Node* head) {
    unordered_set<Node*> hashTable;
    while (head != NULL) {
        if (hashTable.find(head) != hashTable.end())     return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a cycle for testing
    head->next->next->next->next->next = head->next;

    if (cycleDetect(head))      cout << "Cycle detected in the linked list." << endl;
    else    cout << "No cycle detected in the linked list." << endl;

    return 0;
}

==========> APPROACH 2 : SLOW & FAST POINTER USING FUCNTIONS : IN CASE ASKED TO WRITE A FUNCTION FOR INSERT & LOOP FORMATION

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    if(head == NULL || head->next == NULL)    return false;

    while(fast != NULL && fast->next != NULL ) {
        fast = fast->next->next;
        slow = slow->next;

        if(slow==fast)  return true;
    }
    return false;
}

void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void createCycle(node* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    node* p1 = head;
    node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    createCycle(head,1,3);//creating cycle in the list
    if(cycleDetect(head) == true)
    cout<<"Cycle detected\n";
    else
    cout<<"Cycle not detected\n";
    return 0;
}