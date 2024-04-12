class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefProd = 1, sufProd = 1, n = nums.size();
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(prefProd == 0)    prefProd = 1;
            if(sufProd == 0)    sufProd = 1;

            prefProd = prefProd * nums[i];
            sufProd = sufProd * nums[n-i-1];
            ans = max(ans, max(prefProd, sufProd));
        }
        return ans;
    }
};