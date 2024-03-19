class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(low <= high) {
            int mid = (low+high)/2;
            if(isPossible(mid, weights, days)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    bool isPossible(int mid, vector<int>& weights, int days) {
        int daysNeeded = 1, load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] + load > mid) {
                daysNeeded++;
                load = weights[i];
            }
            else    load += weights[i];
            }
        return daysNeeded <= days; 
    }
};