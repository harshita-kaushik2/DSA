class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i]%2;
        }
        
        int count = 0, prefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(auto it: nums) {
            prefixSum += it;
            int exclude = prefixSum - k;
            count += mp[exclude];
            mp[prefixSum] += 1;
        }
        return count;
    }
};