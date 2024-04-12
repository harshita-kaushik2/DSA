APPROACH 1 ===> BRUTE FORCE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
        // Copy elements to temp vector
        for(int i = 0; i < k; i++)
            temp.push_back(nums[n - k + i]);
        
        // Shift elements to the right
        for(int i = n - k - 1; i >= 0; i--)
            nums[i + k] = nums[i];
        
        // Copy elements from temp vector to nums
        for(int i = 0; i < temp.size(); i++) nums[i] = temp[i];
    }
};
