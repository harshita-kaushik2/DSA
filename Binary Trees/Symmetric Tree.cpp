class Solution {
public:
    bool isSymmetricHelper(TreeNode* leftNode, TreeNode* rightNode){
    if(leftNode == NULL || rightNode == NULL)   return leftNode == rightNode;
    if(leftNode->val != rightNode->val)    return false;

    return isSymmetricHelper(leftNode->left, rightNode->right) && isSymmetricHelper(leftNode->right, rightNode->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return isSymmetricHelper(root->left, root->right);
    }
};