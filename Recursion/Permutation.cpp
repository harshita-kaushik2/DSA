/* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]*/

//APPROACH 1 => LESS OPTIMIZED IN TERMS OF SPACE
class Solution {
public:
    void calculate(vector<int>& nums,vector<vector<int>>& ans,int check[],vector<int>&curr){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size();i++){
            if(!check[i]){
                check[i]=1;
                curr.push_back(nums[i]);
                calculate(nums,ans,check,curr);
                curr.pop_back();
                check[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        int check[nums.size()];
        for(int i=0; i<nums.size(); i++)    check[i]=0;
        calculate(nums,ans,check,curr);
        return ans;
    }
};