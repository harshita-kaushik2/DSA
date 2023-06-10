bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }
    else if (x < root->data) {
        return searchInBST(root->left, x);
    }
    else {
        return searchInBST(root->right, x);
    }
}