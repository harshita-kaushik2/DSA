class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int nonZeroes = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                temp.push_back(nums[i]);
                nonZeroes++;
            }    
        }
        for(int i = 0; i < nonZeroes; i++) nums[i] = temp[i];
        for(int i = nonZeroes; i < nums.size(); i++)    nums[i] = 0;
        return;
    }
};