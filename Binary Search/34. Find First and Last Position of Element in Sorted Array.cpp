https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity. */

//METHOD 1 : LOWER BOUND AND UPPER BOUND

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        (low >= 0 && low < n && nums[low] == target )?ans.push_back(low):ans.push_back(-1);
        (up >= 0 && up < n && nums[up] == target)?ans.push_back(up):ans.push_back(-1);

        return ans;
    }
};

//METHOD 2 : BINARY SEARCH IMPLEMENTATION 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> v(2);
        v[0]=-1;
        v[1]=-1;
        int low=0;
        int high=nums.size()-1;

        // First Occurence
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]==target){
                if(mid==0){
                    v[0]=mid;
                    break;
                }
                else if(nums[mid-1]!=target){
                    v[0]=mid;
                    break;
                }
                else{
                    high=mid-1;
                }
            }
            else if(nums[mid]<target) low=mid+1;
            else if(nums[mid]>target) high=mid-1;
        }

        // Second Occurence
        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1) {
                    v[1]=mid;
                    break;
                }
                else if(nums[mid+1]!=target){
                    v[1]=mid;
                    break;
                }
                else{
                   low=mid+1;
                }
            }
            else if(nums[mid]<target) low=mid+1;
            else if(nums[mid]>target) high=mid-1;
        }
        return v;
    }
};