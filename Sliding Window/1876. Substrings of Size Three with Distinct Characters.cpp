https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
/*
A string is good if there are no repeated characters.
Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.

Example 1:
Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0, count = 0;
        unordered_map<char, int> ump;

        for(int j = 0; j < s.size(); j++) {
            ump[s[j]]++;

            if(j - i + 1 == 3) {
                if(ump.size() == 3) count++;

                ump[s[i]]--; 
                
                if(ump[s[i]] == 0) ump.erase(s[i]);
                i++;
            }
        }
        return count;
    }
};