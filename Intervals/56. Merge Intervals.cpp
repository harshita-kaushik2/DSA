// https://leetcode.com/problems/merge-intervals/description/?envType=list&envId=rdmobfev
/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the 
non-overlapping intervals that cover all the intervals in the input.

 
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/


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
