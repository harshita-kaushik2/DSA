https://leetcode.com/problems/generate-parentheses/

/* Only two possible decisions at each point.
Either you open a bracket (if you can) or you close an already opened bracket (if there exists an open one).
*/

class Solution {
public:
    void solve(int remaining, int opened, vector<string>& ans, string& s) {
        if(remaining == 0 && opened == 0){
            ans.push_back(s);
            return;
        }
        if(remaining != 0){
            s += "(";
            solve(remaining - 1, opened + 1, ans, s);
            s.pop_back();
        }
        if(opened != 0) {
            s += ")";
            solve(remaining, opened -1, ans, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ="";
        solve(n, 0, ans, s);
        return ans;
    }
};