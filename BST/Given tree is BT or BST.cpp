lass Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min, long max) {
        if(root == NULL)    return true;
        if(root->val>=max || root->val<=min)    return false;

        bool left = isValidBST(root->left, min, root->val);
        bool right = isValidBST(root->right, root->val, max);

        return left&&right;
    }
};