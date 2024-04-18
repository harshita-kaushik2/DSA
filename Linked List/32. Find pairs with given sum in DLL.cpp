APPRAOCH 1 ==> FINDING ALL PAIRS VIA NESTED LOOPS
/*  Time Complexity: O(n ^ 2)
    Space Complexity: O(1)
*/

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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    Node * ptr1 = head;
    
    while (ptr1 != NULL) {
        Node * ptr2 = ptr1->next;
        while (ptr2 != NULL)   //an optimization that can be done is && ptr1->data + prt2->data <= k only then do it else skip.
        {
            if (ptr1->data + ptr2->data == k)
            {
                ans.push_back(make_pair(ptr1->data, ptr2->data));
            }

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    return ans;
}

APPRAOCH 2 ====> TWO POINTERS. 

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    Node * start = head;
    Node * end = head;

    // Traverse the linked list to the end.
    while (end->next != NULL)   end = end->next;

    while (start->data < end->data) {
        int sum = start->data + end->data;

        if (sum == k) {
            ans.push_back(make_pair(start->data, end->data));
            start = start->next;
            end = end->prev;
        }
        else if (sum < k)   start = start->next;
        else    end = end->prev;

    }
    return ans;
}



