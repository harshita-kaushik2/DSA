//MEMOIZATION ==================================================================================>>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, text1, text2, dp);
    }
    int solve (int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        if(text1[i] == text2[j])   return dp[i][j] = 1+solve(i-1, j-1, text1, text2, dp);
        return dp[i][j] = max(solve(i-1, j, text1, text2, dp), solve(i, j-1, text1, text2, dp));
    }
};

//TABULATION ===================================================================================>>
/*a little tricky => Since the base case in memoization was i<0 we cannot write dp[-1] in tabulation. Thus we need to 
shift the indices to right by 1. Every i that you are giving should be treated as i-1 and so on for j as well. This is 
only done at the time of string comparison or index comparison. No changes to be made to dp array.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        //base cases
        for(int i = 0; i <= n; i++)     dp[i][0] = 0;
        for(int j = 0; j <= m; j++)     dp[0][j] = 0;

        //copy paste recursion via reverse conditions on i & j
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    return dp[n][m];        
    }
};