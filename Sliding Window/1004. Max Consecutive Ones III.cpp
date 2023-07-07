https://leetcode.com/problems/max-consecutive-ones-iii/
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Initialize variables
        int start = 0, end = 0; // Pointers to track the current window
        int ans = 0; // Length of the longest subarray
        int count = 0; // Count of zeros within the window
        int size = nums.size(); // Size of the input array

        // Continue until the end pointer reaches the end of the array
        while (end < size) {
            // Expand the window while count is within the limit
            while (end < size && count <= k) {
                if (nums[end] == 0)
                    count++; // Increment count if a zero is encountered
                if (count <= k)
                    ans = max(ans, end - start + 1); // Update ans if current window is longer
                end++; // Move the end pointer to the right
            }

            // Shrink the window if count exceeds the limit
            while (start <= end && count > k) {
                if (nums[start] == 0)
                    count--; // Decrement count if a zero is encountered
                start++; // Move the start pointer to the right
            }
        }
        return ans; // Return the length of the longest subarray
    }
};