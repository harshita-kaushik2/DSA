#Graphs

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