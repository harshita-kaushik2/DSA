class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;  
        if(root == NULL)    return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int>row (size);
            
            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                int index;
                if(leftToRight == true) index = i;
                else    index = size - i - 1;

                row[index]= curr->val;
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};