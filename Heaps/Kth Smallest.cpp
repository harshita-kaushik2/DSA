int kthSmallest(vector<int> num, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        pq.insert(arr[i]);
    }
    for(int i = k; i < nums.size(); i++) {
        if(nums[i] < pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
