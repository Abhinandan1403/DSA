class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, obstacleGrid, dp);
    }
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            if (grid[i][j] == 1) {
                return 0;
            } else {
                return 1;
            }
        }

        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = 0, left = 0;
        if (grid[i][j] != 1) {
            up = solve(i - 1, j, grid, dp);
            left = solve(i, j - 1, grid, dp);
        }
        return dp[i][j] = up + left;
    }
};