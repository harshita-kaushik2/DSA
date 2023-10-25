class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;

        for(auto x: nums) m[x]++;

        priority_queue<pair<int, int>>pq;

        for(auto p: m) pq.push({p.second, p.first});
        vector<int>res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};