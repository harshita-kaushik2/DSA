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

        if(head==NULL){
            return head;
        }

       ListNode* forward=NULL;
       ListNode* curr=head;
       ListNode* prev=NULL;

       int n=0;
       while(n<k){ 
           if(curr==NULL)
             break;
           curr=curr->next;
           n++;
       }
       if(n!=k){
           return head;
       }

       curr = head;
       n=0;
       while(curr!=NULL&&n<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        n++;
        }
    ListNode* temp=reverseKGroup( curr, k) ;
    head->next=temp;
 return prev;   
    }
};