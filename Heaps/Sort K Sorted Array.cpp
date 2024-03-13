NEARLY SORTED ARRAY :
Given an array of N elements, where each element is at most K away from its target position.

#include <bits/stdc++.h> 
using namespace std;

vector<int> nearlySorted(vector<int> array, int n, int k) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(array[i]);
        if (pq.size() > k) {
            ans.push_back(pq.top());
            pq.pop();
        } 
    }

    // Add remaining elements from the priority queue
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;        
}
