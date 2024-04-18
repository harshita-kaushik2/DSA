#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node * next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

void PrintList(Node * head) {// Function to print the LinkedList
  Node * curr = head;
  while(curr!= NULL) {
        cout << curr -> val << "-->";
        curr = curr->next;
   }
  cout << "null" << endl;
}

Node * InsertatFirst(int value, Node * head) {
  Node * newnode = new Node(value);
  newnode -> next = head;
  head = newnode;
  return head;
}

int main() {
  Node * head = NULL; 
  head = InsertatFirst(40, head);
  head = InsertatFirst(30, head);
  head = InsertatFirst(20, head);
  head = InsertatFirst(10, head);
  cout << "LinkedList before inserting 0 at beginning : " << endl;
  PrintList(head);
  head = InsertatFirst(0, head);
  cout << "LinkedList after inserting 0 at beginning : " << endl;
  PrintList(head);
  return 0;
}