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

  // Step1 : creating a new Node with the given val
  Node * newnode = new Node(value);

  // Step2 : Making next of newly created Node to point the head of LinkedList
  newnode -> next = head;

  // Making the newly created Node as head
  head = newnode;
  return head;
}

int main() {
  Node * head = NULL; // head of the LinkedList
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