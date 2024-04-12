class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        allLeft(root);
    }
    
    void allLeft(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        allLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};