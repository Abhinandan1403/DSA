class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = 0, left = 0;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                    continue;

                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[n - 1][m - 1];
    }
    // int solve(int i, int j, vector<vector<int>>& grid,
    //           vector<vector<int>>& dp) {
    //     if (i == 0 && j == 0) {
    //         if (grid[i][j] == 1) {
    //             return 0;
    //         } else {
    //             return 1;
    //         }
    //     }
    //     if (i < 0 || j < 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int up = 0, left = 0;
    //     if (grid[i][j] != 1) {
    //         up = solve(i - 1, j, grid, dp);
    //         left = solve(i, j - 1, grid, dp);
    //     }
    //     return dp[i][j] = up + left;
    // }
};