https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=top-interview-150

/* Key Point
Identify the sorted half. Search for the element in the sorted half. If it is not present, discard that half and have new low, mid, high for the other half and repeat the process.

To check if the half is sorted or not : if(nums[low] <= nums[mid])
This checks for the left half. If not true, it means right half is sorted.

Approach
The problem gives enough hints by mentioning O(log n) runtime complexity and to search in rotated sorted array that Binary Search is to be applied in this question.

However, unlike usual Binary Search, here we are not sure if the left/right half is sorted or not. 
So you cannot check on one half and be very sure that it would lie on either this half or the other half.

To handle the rotated part of the array, the algorithm checks if the left side of the current mid is sorted (nums[low] <= nums[mid]). 
If it is, it then checks whether the target falls within this sorted range. If so, it narrows down the search space to the left side (high = mid - 1); 
otherwise, it searches the right side (low = mid + 1).

On the other hand, if the left side is not sorted (nums[low] > nums[mid]), then the right side must be sorted. 
In this case, the algorithm checks whether the target falls within the sorted right range. 
If so, it narrows down the search space to the right side (low = mid + 1); otherwise, it searches the left side (high = mid - 1).

The algorithm continues this process until the target element is found or the search space is fully explored. 
If the target is not found, the function returns -1. */

cclass Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] <= nums[high]) {    //means right half is sorted
                //check if target lies in the range
                if(nums[mid] <= target && nums[high] >= target)   low = mid+1;
                else high = mid-1;
            }
            else {  //means left half is sorted
                if(nums[low] <=  target && nums[mid] >= target) high = mid-1;
                else    low = mid+1;
            }
        }
        return -1;
    }
};