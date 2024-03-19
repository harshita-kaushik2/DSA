class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)   return false;
        priority_queue<int, vector<int>, greater<>> pq;
        map<int,int> mp;

        for(auto it: hand)  mp[it]++;
        for(auto it: mp)    pq.push(it.first);

        while(!pq.empty()) {
            int curr = pq.top();
            for(int i = curr; i < curr + groupSize; i++) {
                if(mp.find(i) == mp.end())  return false;

                mp[i]--;
                if(mp[i]==0) {
                    if(i != pq.top())   return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};