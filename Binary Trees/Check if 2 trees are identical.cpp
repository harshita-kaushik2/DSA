class Solution {
public:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL || t2==NULL)
        return t1==t2;

        return (t1->val == t2->val) && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
};