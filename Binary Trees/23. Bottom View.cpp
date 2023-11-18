class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int level = it.second;
            mp[level] = node->data;
            if(node->left != NULL)  q.push({node->left, level-1});
            if(node->right != NULL)  q.push({node->right, level+1});
        }
        vector<int> ans;
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};