vector<int> sumCombinations (vector<int>& a, vector<int>& b, int n, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int,int>>> maxHeap;
    maxHeap.push({a[n-1]+b[n-1], {n-1, n-1}});

    set<pair<int, int>> mySet;
    mySet.insert({n-1, n-1});

    vector<int> ans;

    while(k > 0) {
        pair<int, pair<int,int>> = maxHeap.top();
        maxHeap.top();
        int sum = top.first;
        int x = top.second.first;
        int y = top.second.second;

        ans.push_back(sum);
    }
}