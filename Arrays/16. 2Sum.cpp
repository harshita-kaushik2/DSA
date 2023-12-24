class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i < nums.size(); i++) {
            int num1 = nums[i];
            int num2 = target - nums[i];
            if(mp.find(num2) != mp.end())   return {mp[num2],i};
            mp[num1]=i;
        }
        return {-1,-1};
    }
};

MOST OPTIMISED APPROACH =======================================================================================>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; 
        int n = numbers.size();
        int right = n - 1; 
        vector<int> ans;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans; 
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }
        return {-1, -1}; 
    }
};
