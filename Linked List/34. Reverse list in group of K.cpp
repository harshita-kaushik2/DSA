Question link : https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan
/*
Approach :
Step 1 : Ek group ka kar do reverse. Baaki ko recursion sambhaal lega. 
Step 2 : Reverse karne ke baad, head will be on the last element of group. Toh we need to insert the output of recusion at head->next
Step 3 : Return head of reversed linked list, that is prev pointer.
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( head == NULL)   return NULL;
        ListNode* temp = head;
      
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        if(!possible(head,k))   return head;

        while(curr != NULL && count < k)    {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count ++;
        }

        if ( forward != NULL ) {
            head -> next = reverseKGroup(forward, k);
        } 
        return prev;
    }

    bool possible(ListNode* head, int k) {
        ListNode* temp = head;
        int length=0;

        while(temp != NULL) {
            temp=temp->next;
            length++;
            if(length >=k) return true;
        }
        return false;
    }
};