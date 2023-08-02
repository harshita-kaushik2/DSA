https://leetcode.com/problems/combination-sum/description/
//instead of making a sum variable and them adding values and then comparing it with the target, we subtract value of element from target.

class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int target) {
        if(index == candidates.size() && target == 0 )  {
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[index] <= target) {
            curr.push_back(candidates[index]);
            solve(index, candidates, ans, curr, target-candidates[index]);
            curr.pop_back();
        }
        solve(index+1, candidates, ans, curr, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, candidates, ans, curr, target);
        return ans; 
    }
};