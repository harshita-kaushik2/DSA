https://leetcode.com/problems/search-insert-position/description/
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/
//METHOD 1 : IMPLEMENTING LOWER BOUND

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size(), mid = 0;
        if(target > nums[high-1])     return high;

        while(low <= high){
            mid = (low+high)/2;

            if(nums[mid] == target)  return mid;
            if(target < nums[mid]) high=mid-1;    
            else     low = mid+1;        
        }
        return  low;   
    }
};

//METHOD 2 : LOWER BOUND STL 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};