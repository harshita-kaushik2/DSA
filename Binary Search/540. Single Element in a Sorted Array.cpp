//TAREEKA 1 => USING MID^1 TO FIND INDEX. IF MID IS ODD, MID^1 GIVES PREVIOUS INDEX, IF MID IS EVEN, MID^1 GIVES NEXT INDEX.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == nums[mid^1]) low = mid + 1;
            else    high = mid - 1;
        }
        return nums[low];
    }
};

//TAREEKA 2 => EASIER 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] != nums[mid + 1]) right = mid;
            else left = mid + 2;
        }
        return nums[left];
    }
};