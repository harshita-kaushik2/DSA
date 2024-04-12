class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        
        for(int i = 0; i < V; i++){                     //converting adj matric to list
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {      //remember the i != j condition
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
    void dfs(int index, vector<int> adj[], vector<int> &vis){
        vis[index] = 1;
        for(auto it : adj[index]) {
            if(!vis[it]) {
                vis[it] = 1;
                dfs(it, adj, vis);
            }
        }
    }
};