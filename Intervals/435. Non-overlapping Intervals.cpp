// https://leetcode.com/problems/non-overlapping-intervals/
// https://www.youtube.com/watch?v=nONCGxWoUfM
/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make
the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int curr_end = intervals[0][1];
        int count = 0;

        for(int i = 1; i<intervals.size(); i++){
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];
            if(next_start < curr_end ) {
                count++;
                curr_end = min(curr_end, next_end);
            }
            else    curr_end = next_end;
        }
        return count;
    }
};

