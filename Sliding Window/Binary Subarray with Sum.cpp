class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        int start = 0, end = 0, ans = 0, count = 0;
        if(goal < 0)    return 0;

        while (end < nums.size()) {
            count += nums[end];
            
            while (count > goal) {
                count -= nums[start];
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
