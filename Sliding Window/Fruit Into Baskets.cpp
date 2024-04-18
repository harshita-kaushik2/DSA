Approach 1 = Sliding Window TC = n+n

function(vector<int> arr) {
    int start = 0, end = 0, maxLen = 0;
    unordered_map<int, int> mpp;

    while(end < arr.size()) {
        mpp[arr[end]]++;
        if(mpp.size() > k) {
            while(mpp.size() > k) {
                mpp[arr[start]]--;
                if(mpp[arr[start]] == 0)    mpp.erase(arr[start]);
                start++;
            }
        }
        if(mpp.size() <= k) {
            maxLen = max(maxLen, end - start + 1);
        }
        right++;
    }
    return maxLen;
}

APPROACH 2 = Sliding Window using O(n)
