# Graphs

## I. BFS Traversal
1. Choose a starting vertex or node from which you want to begin the traversal.
2. Create a queue data structure to store the nodes that need to be visited. Initialize the queue with the starting node.
3. Create a visited array to keep track of the nodes that have been visited during the traversal. Add the starting node to the visited array.
4. While the queue is not empty, repeat steps 5-8:
5. Dequeue a node from the front of the queue. This will be the current node.
6. Process the current node. This can be performing any desired actions or just adding the node to a list to keep track of the traversal order.
7. Get all the neighboring nodes of the current node from the adjacency list (that have not been visited yet). 
Add these neighbors to the queue and mark them as visited.
8. Repeat steps 5-7 until the queue becomes empty.
9. Once the queue is empty, the BFS traversal is complete.

```cpp
vector<int> bfs(vector<vector<int>>& graph, int start) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(start);
    visited.insert(start);
    vector<int> bfs;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        bfs.push_back(current);

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    return bfs;
}
```

## II. DFS Traversal 
1. Choose a starting vertex or node from which you want to begin the traversal.
2. Create a visited set or array to keep track of the nodes that have been visited during the traversal. Initially, mark all nodes as unvisited.
3. Create a recursive function (or use a stack) to implement the DFS traversal. This function will take the current node as a parameter.
4. Mark the current node as visited.
5. Process the current node. This can be performing any desired actions or just adding the node to a list to keep track of the traversal order.
6. Recursively traverse all the unvisited neighboring nodes of the current node by calling the DFS function on each neighbor.
7. Repeat steps 4-6 until all reachable nodes are visited.
```cpp
void dfs(vector<vector<int>>& graph, int current, unordered_set<int>& visited, vector<int>& dfs) {
    visited.insert(current);

    // Process current node
    dfs.push_back(current);

    for (int neighbor : graph[current]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    vector<int> dfs;
    dfs(graph, start, visited, dfs);
    return dfs;
}
```
## 3. Traversal across 2D matrix type Graphs
```cpp
int n = mat.size();
int m = mat[0].size();
    
    //traversal
for(int i = 0;i<4;i++) {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
        if(nrow >=0 && ncol >= 0 && nrow <n && ncol < m  && !vis[nrow][ncol] && whatever condition the question demands) {
            ...
        }
    }
}

int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1}; 
```
---
## Dectecting Cycle in Undirected Graph (BFS)
1.  Push the pair of the source node and its parent data (<source, parent>) in the queue, and mark the node as visited. The parent will be needed so that we don’t do a backward traversal in the graph, we just move frontwards. 
2.  Start the BFS traversal, pop out an element from the queue every time and travel to all its unvisited neighbors using an adjacency list.
3.  Repeat the steps either until the queue becomes empty, or a node appears to be already visited which is not the parent, even though we traveled in different directions during the traversal, indicating there is a cycle.
4.  If the queue becomes empty and no such node is found then there is no cycle in the graph
```cpp
bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      queue<pair<int,int>> q;                                // store <source node, parent node>
      q.push({src, -1}); 
      
      while(!q.empty()) {                                   // traverse until queue is not empty
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          for(auto adjacentNode: adj[node]) {                 // go to all adjacent nodes
              if(!vis[adjacentNode]) {                      // if adjacent node is unvisited
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  return true;                              // yes it is a cycle
              }
          }
      }
    return false;         // there's no cycle
  }
  bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {                        //for the disconnected components of the graph that might have cycle
            if(!vis[i]) 
                if(detect(i, adj, vis)) return true; 
        }
    return false; 
}
```

## Detect Cycle in Undirected Graph (DFS)
1.  In the DFS function call make sure to store the parent data along with the source node, create a visited array, and initialize to 0. The parent is stored so that while checking for re-visited nodes, we don’t check for parents. 
2.  We run through all the unvisited adjacent nodes using an adjacency list and call the recursive dfs function. Also, mark the node as visited.
3.  If we come across a node that is already marked as visited and is not a parent node, then keep on returning true indicating the presence of a cycle; otherwise return false after all the adjacent nodes have been checked and we did not find a cycle.
```cpp
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1; 
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) {                           // unvisited adjacent node
            if(dfs(adjacentNode, node, vis, adj) == true) 
                return true; 
        }
        else if(adjacentNode != parent) return true;    // visited node but not a parent node
    }
    return false; 
}
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};  
    for(int i = 0;i<V;i++) {                         // for graph with connected components
        if(!vis[i]) 
            if(dfs(i, -1, vis, adj) == true) return true; 
       }
    return false; 
}
```
___
## Topological Sort
Topo Sort of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.  

#### Why Topological Sort exists only in DAG (Directed Acyclic Graph) : 
- Case 1 (If the edges are undirected): 
If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.

- Case 2(If the directed graph contains a cycle): 
The following directed graph contains a cycle:
If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.

```cpp

```