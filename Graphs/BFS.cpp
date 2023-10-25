#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0);         // push the initial starting node 
        vector<int> bfs; 

        while(!q.empty()) {                // iterate till the queue is empty 
            int node = q.front();         // get the topmost element in the queue 
            q.pop(); 
            bfs.push_back(node); 
            for(auto it : adj[node]) {              // traverse for all its neighbours 
                if(!vis[it]) {                      // if the neighbour has previously not been visited, 
                    vis[it] = 1;                    // store in Q and mark as visited 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}