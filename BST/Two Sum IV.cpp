class BSTIterator {
    stack<TreeNode*> st;
    //reverse : true -> back
    //reverse : false -> next
    bool reverse = true;
public : 
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next () {
        TreeNode *tmpNode = st.top();
        st.pop();
        if(!reverse)    pushAll(tmpNode->right);
        else            pushAll(tmpNode->left);
        return tmpNode->val;
    }
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            st.push(node);
            if(reverse == true) node = node->right;
            else    node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)    return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while(i < j) {
            if(i+j == k)    return true;
            else if (i+j < k)   i = left.next();
            else    j = right.next();
        }
        return false;
    }
};