/*
Pen paper pe karne wala question hai yeh. Pointers ke saath manipulation is better understood when done on paper. Refer to notes for approach
Overview : Pass head of whichever list has smaller element as first. Creat pointers, curr1 next1 and curr2 next2. 
- Check if you can insert curr2 between curr1 and next1. next2 is only to retain the list 2.
- If we cannot instert curr2 between curr1 and next1, we move the pointers ahead staying mindful of the end of list 1.
- If we reach the end of list 1, which means next1 points to null, we point curr1->next to remaining list2.
*/



class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2) {
        if(list1->next == NULL)  {
            list1->next = list2;
            return list1;
        }
        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2->next;

        while(next1 != NULL && curr2 != NULL) {
            if((curr1->val <= curr2->val) && (curr2->val <= next1->val)) {
               curr1->next = curr2;
               next2 = curr2->next;
               curr2->next = next1;

               curr1 = curr2;
               curr2 = next2;
            }

            else {
                curr1=curr1->next;
                next1=next1->next;

                if(next1 == NULL){
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)  return list2;
        if(list2 == NULL)  return list1;

        if(list1->val <= list2->val)  
        return solve(list1, list2);
        else
        return solve(list2, list1);
    }
};