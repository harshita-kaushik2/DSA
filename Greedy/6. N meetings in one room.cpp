//incomplete code

#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int startTime[], int endTime[], int n) {
    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++) {
        pair<int, int> val = make_pair(startTime[i], endTime[i]);
        arr.push_back(val);
    }
    sort(ans.begin(), ans.end(), cmp);

    int limit = ans[0].second;
    int count = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i].first > limit) {
            count++;
            limit = arr[i].second;
        }
    }
    return count;
}

static bool cmp(pair<int, int> prev, pair<int, int> next) {
    return prev.second < next.second;
}

int main () {
    return 0;
}