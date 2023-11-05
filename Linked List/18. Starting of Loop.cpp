APPROACH 1 : USING EXTRA SPACE AS HASHMAP
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};

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

void createCycle(Node* &head, int pos) {
    Node* ptr = head;
    Node* temp = head;
    int cnt = 0;
    while (temp->next != NULL) {
        if (cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

// Process as per mentioned in solution
Node* detectCycle(Node* head) {
    unordered_set<Node*> st;
    while (head != NULL) {
        if (st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 6);
    insertNode(head, 10);
    
    createCycle(head, 2);
    
    Node* nodeReceive = detectCycle(head);
    if (nodeReceive == NULL) {
        cout << "No cycle";
    } else {
        Node* temp = head;
        int pos = 0;
        while (temp != nodeReceive) {
            ++pos;
            temp = temp->next;
        }
        cout << "Tail connects at pos " << pos << endl;
    }
    
    return 0;
}


==========> APPROACH 2 : USING SLOW AND FAST POINTER

