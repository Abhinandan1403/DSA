class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2 && !vis[i][j]) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        int ans = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            int t = it.first;
            ans = max(ans, t);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && ny < m && nx < n &&
                    grid[nx][ny] == 1 && !vis[nx][ny]) {
                    q.push({t + 1, {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return ans;
    }
};