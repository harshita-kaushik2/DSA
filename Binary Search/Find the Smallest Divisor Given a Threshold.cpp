class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (possible(m, nums, threshold)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
    
    bool possible(int m, vector<int>& nums, int threshold) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / m);      
        }
        return sum <= threshold;
    }
};

