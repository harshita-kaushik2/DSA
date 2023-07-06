Link : https://leetcode.com/problems/reverse-pairs/
/*  Return the number of reverse pairs in the given array.
A reverse pair is a pair (i, j) where:
i. i < j
ii. nums[i] >  nums[j].  */

/*  BRUTE FORCE => Traverse through the entire array for each element. TC = O(n^2) SC = O(1).  */

/*INTUTION => Think of two different arrays, both of which are sorted. Now you have to pick one element 'i' 
from the first and find an element in second array whose value is smaller than 'i'. 

KEY IDEA : If an element in 2nd array is smmaller than current 'i' (which is in turn smaller than all
the elements on its right since the arrays are sorted) that element is also smaller than all the other
elements on the right of 'i'. So instead of counting +1 +1, we count +(no of elements on right).

Eg. arr1 = [2,3,5,6] and arr2 = [2,2,4,4,8] when i = 3, j = 2. for the given 'j' since it is smaller than 'i'
which is in turn smaller than 5 and 6 on its right, for this we add a +3 instead of +1.
*/

/* APPROACH => Modifications in merge() and mergeSort(): 
- In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
- While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line:
cnt += mid-left+1 (mid+1 = size of the left half)
- Now, we will return this cnt from merge() to mergeSort(). 
- Inside mergeSort(), we will keep another counter variable that will store the final answer. With this cnt, we will add the answer returned from mergeSort() of the left half, mergeSort() of the right half, and merge().
- Finally, we will return this cnt, as our answer from mergeSort().*/

