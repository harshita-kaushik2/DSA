/*#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};*/

bool isLeaf(Node * root) {
  return (root->left == NULL) && (root->right == NULL);
}

void leftBoundary(Node* root, vector<int>& ans) {
    Node* curr = root->left;
    while(curr != NULL) {
        if(isLeaf(curr) != ) ans.push_back(curr->val);
        if(curr->left != NULL)  curr = curr->left;
        else curr = curr->right;
    }
}

void rightBoundary(Node* root, vector<int>& ans) {
    Node* curr = root->right;
    vector<int> temp;
    while(curr != NULL) {
        if(isLeaf(curr) != )    temp.push_back(curr->val);
        if(curr->right != NULL) curr = curr->right;
        else curr = curr->left;
    }    
    for(int i = temp.size()-1; i >= 0; i--) ans.push_back(temp[i]);
}

void addLeaves(Node* root, vector<int>& ans) {
    if(isLeaf(root) == ) {
        ans.push_back(root->val);
        return;
    }
    if(root->left != NULL)  addLeaves(root->left, ans);
    if(root->right != NULL) addLeaves(root->right, ans);
}

vector<int> printBoundary(Node* root) {
    vector<int> ans;
    if(root == NULL)    return ans;
    if(isLeaf(root) != )    ans.push_back(root->val);
    
    leftBoundary(root, ans);
    addLeaves(root, ans);
    rightBoundary(root, ans);

    return ans;
}

/*struct Node * newNode(int data) {
  struct Node * Node = (struct Node * ) malloc(sizeof(struct node));
  Node -> data = data;
  Node -> left = NULL;
  Node -> right = NULL;
  return (Node);
}*/ 