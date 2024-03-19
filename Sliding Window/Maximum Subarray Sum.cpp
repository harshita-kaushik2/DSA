APPROACH 1 => start a window with 0 elements from left, keep on adding elements one by one, whenever the sum is less than 0 remove elements from left until sum becomes positive again. Update ans if tempSum > alignas

Note : CONCEPT OF STORING LENGTH IS IMPORTANT HERE.  it is used to ensure that only non-empty subarrays are considered. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tempSum = 0, ans = INT_MIN, start = 0, length = 0;

        for(int i=0; i<nums.size(); i++){
            tempSum += nums[i]; 
            length++; 
            if(length > 0 &&  tempSum > ans) ans = tempSum; 
            
            while(tempSum < 0 ){
                tempSum -= nums[start]; 
                start++; 
                length--; 
            }
            if(length > 0 &&  tempSum > ans) ans = tempSum; 
        }
        return ans;  
    }
};

APPROACH 2 => DYNAMIC PROGRAMMING