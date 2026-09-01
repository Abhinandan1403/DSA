class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m,  vector<vector<vector<int>>>&dp) {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e8;
        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int curr = grid[i][j1];
        if (j1 != j2) {
            curr += grid[i][j2];
        }
        int maxi = 0;
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                int take = solve(i + 1, j1 + a, j2 + b, grid, n, m,dp);
                maxi = max(maxi, take);
            }
        }
        return dp[i][j1][j2]= maxi + curr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(0, 0, m - 1, grid, n, m,dp);
    }
};