/*
Pen paper pe karne wala question hai yeh. Pointers ke saath manipulation is better understood when done on paper. Refer to notes for approach
Overview : Pass head of whichever list has smaller element as first. Creat pointers, curr1 next1 and curr2 next2. 
- Check if you can insert curr2 between curr1 and next1. next2 is only to retain the list 2.
- If we cannot instert curr2 between curr1 and next1, we move the pointers ahead staying mindful of the end of list 1.
- If we reach the end of list 1, which means next1 points to null, we point curr1->next to remaining list2.
*/
