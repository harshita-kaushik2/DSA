class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;   
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){ 
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(head){
           forward=head->next;
           head->next=prev;
           prev=head;
           head=forward; 
        }
        return prev;
    }

    void reorderList(ListNode* head) {
         ListNode* mid=getMiddle(head);
         ListNode* head2=reverseList(mid->next);
         mid->next=NULL; 

         while(head && head2){
             ListNode* next1 = head->next;     
             ListNode* next2 = head2->next;
             head->next = head2;          
             head->next->next = next1;
             head = next1;
             head2 = next2;
         }
    }
};