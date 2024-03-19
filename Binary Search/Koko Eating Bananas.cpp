class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1; 
       int high = *max_element(piles.begin(), piles.end()); 
       int ans = -1;

       while(low <= high) {
        int mid = low + (high - low)/2;

        long long totalHr = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalHr += ceil((double)piles[i]/mid); 
        }     
        if(totalHr <= h) {
            ans = mid;
            high = mid-1;
        }   
        
        else low = mid+1;
       } 
       return ans;
    }
};
