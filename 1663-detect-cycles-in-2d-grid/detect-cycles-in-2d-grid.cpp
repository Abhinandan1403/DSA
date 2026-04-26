class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    char ch = grid[i][j];
                    if (dfs(i, j, -1, -1, ch, grid, vis) == true)
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(int r, int c, int pr, int pc, char ch, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        vis[r][c] = 1;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> del = {0, 1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = r + del[i];
            int nc = c + del[i + 1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == ch) {

                if (!vis[nr][nc]) {
                    if (dfs(nr, nc, r, c, ch, grid, vis))
                        return true;
                } else if (!(nr == pr && nc == pc)) {
                    return true;
                }
            }
        }
        return false;
    }
};