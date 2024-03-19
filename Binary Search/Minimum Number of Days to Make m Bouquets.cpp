class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())  return -1;
        int ans = -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l <= r) {
            int mid = (l + r) / 2;
            if (possible(mid, bloomDay, m, k)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }

    bool possible(int mid, vector<int>& bloomDay, int m, int k) {
        int count = 0, buk = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    buk++;
                    count = 0;
                }
            } 
            else    count = 0;
        }
        return buk >= m;
    }
};
