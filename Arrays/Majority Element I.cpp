class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto element : mp) {
            if (element.second > nums.size() / 2) {
                ans = element.first;
                break;
            }
        }
        return ans;
    }
};
