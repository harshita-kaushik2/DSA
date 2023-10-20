Link : https://leetcode.com/problems/next-permutation/
/*Problem Statement : The next permutation of an array of integers is the next lexicographically greater permutation of its integer
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.*/

/*BRUTE FORCE : 1. Find all the permutations in sorted order 2. Linear search to find where does the current permutation lies
3.If it is not at the last, its next index is answer. If it is last, first index is the answer */

/*APPROACH 2 => STL : next_permutation (arr.begin(), arr.end())*/

/*APPROACH 3 => IMPLEMENTING THAT STL
- Try looking out for longer prefix match as one can observe happens in the next element in a dictionary
- Find the break point. When you find it swap with someone who is slightly larger than the break point. Smallest larger number to the right
- Fill the remaining spaces to the right by making as small integer as possible i.e., by sorting.
- Edge case : If there is no dip, this means that current is the largest permutation. Thus, return the reverse of it. */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        for(int i = nums.size() - 2; i >= 0; i--) { //finding the break point
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        if(ind == -1)   {
            reverse(nums.begin(), nums.end());  //checking if no break point exists
            return;
        }
        for(int n = nums.size()-1; n > ind; n--) {  //swapping with smallest element greater than arr[ind]
            if(nums[n] > nums[ind]) {
                swap(nums[n], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.end());    //generating next permutation
    }
};
