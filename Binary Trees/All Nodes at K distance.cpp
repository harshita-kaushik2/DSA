class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int, TreeNode*> parent;       //get a track of the parent nodes via BFS traversal starting from root
        queue<TreeNode*> q;                         
        q.push(root);

        while(!q.empty()){
            int si = q.size();
            for(int i = 0; i < si; i++){
                auto top = q.front();
                q.pop();
                
                if(top -> left){
                    parent[top->left->val] = top;         //marking parent
                    q.push(top->left); 
                }

                if(top -> right){
                    parent[top->right->val] = top;      //marking parent
                    q.push(top->right); 
                }
            }
        }

        unordered_map<int, int> visited;            //keeping track of visited nodes to not travel backwards to same node
        q.push(target);                             //starting with target node jis se distance nikalni thi nodes ki
        while(k-- && !q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto top = q.front();
                q.pop();

                visited[top -> val] = 1;        //mark every popped node as visited

                if(top -> left && !visited[top->left->val]) q.push(top -> left);
                if(top -> right && !visited[top->right->val])   q.push(top -> right);
                if(parent[top->val] && !visited[parent[top->val] -> val])   q.push(parent[top->val]);   //careful
            }
        }

        while(!q.empty()){              //transfer nodes remaining to a vector and return it
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};