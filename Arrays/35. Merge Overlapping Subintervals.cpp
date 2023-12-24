// METHOD 1 : TC = O(N log N) + O( N + N )
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); 

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1])     continue;

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end)       end = max(end, arr[j][1]);
            else     break;
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

// OPTMIZED APPROACH : O(N LOG N) + O(N)

class Solution {
public:
    static bool compareInterval(const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareInterval);
        vector<vector<int>> ans;
        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];

            if (next_start <= curr_end) {
                curr_end = max(curr_end, next_end);
            } 
            else {
                ans.push_back({ curr_start, curr_end });
                curr_start = next_start;
                curr_end = next_end;
            }
        }
        ans.push_back({ curr_start, curr_end });
        return ans;
    }
};

