int maxDepth(TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    int lH = maxDepth(root->left);
    int rH = maxDepth(root->right);

    return (1 + max(lH, rH));
}