https://leetcode.com/problems/number-of-provinces/
/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
*/

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node]=1;
        for (auto it : adj[node]){
            if(!vis[it])
                dfs(it, vis, adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int cnt=0;
        vector<int> vis(n+1,0);
        vector<int> adj[n+1];
        for (int i=0; i<n; i++){                    //Converting given adjacency matrix to adjacency list
            for (int j=0; j<n; j++){
                if (isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        for (int i=1; i<=n; i++){           //Iterating over the visited array to find the starting point of the province
            if(!vis[i]){
                cnt++;                      //Counting the number of times a seperate province was found
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};