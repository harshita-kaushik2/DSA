APPROACH 1 ==> IMKDAM BRUTE FORCE : TC = O(N^2)
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        
        for(int i = 0; i < n; i++) {
            int pro = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                pro *= nums[j];
            }
            ans[i] = pro;
        }
        
        return ans;
    }
}

APPROACH 2 ==> MULTIPLY ALL NUMBERS AND THEN DIVIDE BY CURRENT NUMBER, PROBLEM WHEN NUMBER TO BE DIVIDED BY IS 0.
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        int pro = 1;
        for(int i : nums) {
            pro *= i;
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = pro / nums[i];
        }
        return ans;
    }
}

APPRAOCH 3 ==> PREFIX PRODUCT ARRAY & POSTFIX PRODUCT ARRAY 


APPROACH 4 ==> 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1); 
        int curr=1;

        for(int i=0; i<n; i++) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        curr=1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *= curr;
            curr *= nums[i];
        }
        return ans;
    }
};
