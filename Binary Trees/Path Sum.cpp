class Solution {
public:
    bool rootToLeafPathSum(TreeNode* root, int targetSum, int sum) {
        if (root == NULL)  return false;

        if (root->left == NULL && root->right == NULL) {
            sum = sum + root->val;
            if (sum == targetSum)  return true;
        }
        return rootToLeafPathSum(root->left, targetSum, sum + root->val) ||
               rootToLeafPathSum(root->right, targetSum, sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return rootToLeafPathSum(root, targetSum, sum);
    }
};