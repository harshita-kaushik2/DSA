APPROACH 1 => 
DO A TRAVERSAL : INORDER/PRE-ORDER/POST-ORDER
TC = O(N)
AUXILLARY SC = O(h) and h in a CBT is logN. 


APPROACH 2 =>
class Solution {
public:
    int countNodes(TreeNode* root) {
       if(root==NULL)   return 0;
       int lh =  findLeftHeight(root);
       int rh = findRightHeight(root);
       if(lh==rh) return (1<<lh)-1;

       return 1+countNodes(root->left)+countNodes(root->right);
    }

    int findLeftHeight(TreeNode* node){
        int height=0;
        while(node != NULL){
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node){
        int height=0;
        while(node != NULL){
            height++;
            node = node->right;
        }
        return height;
    }

};