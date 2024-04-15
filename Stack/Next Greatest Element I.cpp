class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1); 
        stack<int> st;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums2.size(); i++) {
            int curr = nums2[i];

            while (!st.empty() && curr > st.top()) {
                mpp[st.top()] = curr;
                st.pop();
            }
            st.push(curr);
        }

        for (int i = 0; i < nums1.size(); i++) {
            int ele = nums1[i];

            if (mpp.find(ele) != mpp.end()) {
                int nge = mpp[ele];
                res[i] = nge; 
            }
        }
        return res;
    }
};