class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, m-1, n-1, grid, dp);
    }

    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>m || j>n){
            return 0 ;
        }
        if(grid[i][j]){
            return 0 ;
        }
        if(i == m && j == n){
            return 1 ;
        }
        

        if(dp[i][j] != -1)return dp[i][j];

        int right = solve(i+1, j, m, n, grid, dp);
        int down = solve(i, j+1, m, n, grid, dp);

        return dp[i][j] = right+down;
    }
};