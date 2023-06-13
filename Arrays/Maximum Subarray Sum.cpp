Link : https://leetcode.com/problems/maximum-subarray/description/
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/
/*
Approach => KADANE'S ALGORITHM
1. Initialize two variables, maximumSum and currSumSubarray to the minimum integer value (INT_MIN) and 0, respectively.
2. Loop through the array from index 0 to n-1, where n is the size of the array.
3. In each iteration, add the current element of the array to the currSumSubarray variable.
4. Take the maximum between maximumSum and currSumSubarray and store it in the maximumSum variable.
5. Take the maximum between currSumSubarray and 0 and store it in currSumSubarray. This is done because if the currSumSubarray becomes negative, it means that we should start a new subarray, so we reset currSumSubarray to 0.
6. After the loop ends, return the maximumSum variable, which contains the maximum sum of a subarray
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //maximumSum will calculate our ans and currSumSubarray will calculate maximum sum subarray till ith position 
        int maximumSum = INT_MIN, currSumSubarray = 0;
        for (int i = 0; i < n; i++) {
            currSumSubarray += nums[i]; 
            maximumSum = max(maximumSum, currSumSubarray);
            //here we are taking max with 0 bcz if currSumSubarray = -1 or any negative value then it again starts with currSumSubarray = 0
            currSumSubarray = max(currSumSubarray, 0);
        } 
        return maximumSum;
    }
};