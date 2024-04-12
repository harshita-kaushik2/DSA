class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0, end = 0;
        long long tempSum = 0, ans = 0;
        set<int> st;

        while(end < nums.size()) {
            if(st.size() == k) {
                ans = max(ans, tempSum);
                tempSum -= nums[start];
                st.erase(nums[start]);
                start++;
            }
            else if(st.find(nums[end]) == st.end()) {
                st.insert(nums[end]);
                tempSum += nums[end];
                end++;
            }
            else { 
                tempSum -= nums[start];
                st.erase(nums[start]);
                start++;
            }
        }

        if(st.size() == k)   ans = max(ans, tempSum);
        return ans;        
    }
};
