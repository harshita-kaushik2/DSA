class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;

        for (auto it : nums) {
            freq[it]++;
        }

        int maxi = INT_MIN;                     //how to count maximum frequency element from array
        for (auto it : freq) {
            maxi = max(maxi, it.second);
        }

        for (int i = 0; i < maxi; i++) {
            vector<int> subAns;
            vector<int> keys;

            for (auto it : freq) {
                keys.push_back(it.first);       //how we will select elements from map & erase them one-by-one
            }

            for (auto key : keys) {
                subAns.push_back(key);
                freq[key]--;

                if (freq[key] == 0) {       //how we erase elements. We do not if(it.second == 0)   freq.erase(it); 
                    freq.erase(key);
                }
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};
