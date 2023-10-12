// BRUTE FORCE : O(N^2)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)    return 0;

        int lHeight = calcHeight(root->left);
        int rHeight = calcHeight(root->right);

        int currDiameter = lHeight + rHeight ;

        int lDia = diameterOfBinaryTree(root->left);
        int rDia = diameterOfBinaryTree(root->right);

        return max(currDiameter, max(lDia,rDia));
        }

    int calcHeight(TreeNode* root) {
        if(root == NULL)    return 0;

        int lh = calcHeight(root->left);
        int rh = calcHeight(root->right);

        return max(lh,rh)+ 1;
    }
};

// OPTIMIZED APPROACH : O(N)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

     int height(TreeNode* node, int& diameter) {

        if (node == NULL)   return 0;

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};