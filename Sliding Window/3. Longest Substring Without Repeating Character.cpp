class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;

        for(int ind = 0; ind < s.size(); ind++) {
            if(mp.count(s[ind])==0 || mp[s[ind]] < start) {
                mp[s[ind]] = ind;
                maxLen = max(maxLen, ind - start + 1);
            }
            else {
                start = mp[s[ind]] + 1;
                mp[s[ind]] = ind;
            }
        }
        return maxLen;        
    }
};