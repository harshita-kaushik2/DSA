#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int findCeil(Node* root, int num) {
    int ceil = -1;
    
    while (root != NULL) {
        if (root->val == num) {
            ceil = root->val;
            return ceil;
        }
        if (root->val < num) {
            root = root->right;
        } 
        else {
            ceil = root->val;
            root = root->left;
        }
    }
    
    return ceil;
}

int main() {
    // Example usage:
    // Construct a sample BST
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int num = 5;
    int result = findCeil(root, num);

    cout << "The ceil of " << num << " is: " << result << endl;

    // Don't forget to free the allocated memory
    // You may use a proper deallocation function based on your needs
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
