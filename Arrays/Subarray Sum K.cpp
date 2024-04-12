class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
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