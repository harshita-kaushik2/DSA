#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL, right = NULL;
    }
};

vector<int> topView(Node* root) {
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int, int> mpp; 
    queue<pair<Node*, int>> q; 
    q.push({root, 0}); 
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        Node* node = it.first; 
        int line = it.second; 
        if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
        
        if(node->left != NULL)      q.push({node->left, line - 1}); 
        
        if(node->right != NULL)     q.push({node->right, line + 1}); 
    }
    
    for(auto it : mpp)  ans.push_back(it.second); 
    return ans; 
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> result = topView(root);

    cout << "Top View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
