Link : https://leetcode.com/problems/minimum-size-subarray-sum/
/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/
The idea is to maintain two pointers, start and end, which define the current subarray we are considering. 
We'll move the end pointer to expand the subarray and the start pointer to shrink it whenever the sum of the subarray exceeds the target.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, minLen = INT_MAX, sum = 0;
        int size = nums.size();

        while(end < size){
            sum += nums[end];
            
            while(sum >= target ){
                minLen = min(minLen, end-start+1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return (minLen == INT_MAX)?0:minLen;
    }
};