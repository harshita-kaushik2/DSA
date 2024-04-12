class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0, end=0, maxFreq=0, res=0;
        unordered_map<char, int>mp;

        while(end < s.size()) {
            mp[s[end]]++;
            maxFreq = max(maxFreq ,mp[s[end]]);

            if(end-start+1-maxFreq > k){
                mp[s[start]]--;
                start++;
            }
            res=max(res, end-start+1);
            end++;
        }
       return res; 
    }
};