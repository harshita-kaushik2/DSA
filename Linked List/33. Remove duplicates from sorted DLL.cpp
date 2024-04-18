/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head) {
    Node * cur = head;

    while (cur != NULL && cur -> next != NULL) {
        // Next element has same value as the current element
        if (cur -> next -> data == cur -> data) {
            cur -> next = cur -> next -> next;  // Adjust links to remove the next element
        }

        else {      // Next element is different from the current element
            cur = cur -> next;
        }
    }
    return head;
}
