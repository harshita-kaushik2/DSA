class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        int total_fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } 
                else    vis[i][j] = 0;
                if (grid[i][j] == 1)    total_fresh++;
            }
        }

        int tm = 0;
        int drow[] = {0, -1, 1, 0};
        int dcol[] = {1, 0, 0, -1};
        int rotted = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                tm = max(tm, t);

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    rotted++;
                }
            }
        }

        if (rotted != total_fresh)  return -1;
        else     return tm;
    }
};