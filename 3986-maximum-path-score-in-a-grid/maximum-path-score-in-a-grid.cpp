class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
       vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(k+1,-1)));
        int ans= solve(grid, 0, 0, k,dp);
        return ans==INT_MIN?-1:ans;
    }

    int solve(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<long long>>> &dp){
        int m = grid.size();
        int n = grid[0].size();
       
        if(i>m-1 || j>n-1 || k<0){
            return INT_MIN;
        }
         if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int cost=grid[i][j]==0?0:1;
        int score=grid[i][j]==0?0:(grid[i][j]==1?1:2);
        if(i == m-1 && j == n-1){
            if(k-cost<0) return INT_MIN;

            return dp[i][j][k]=grid[i][j] ;
        }
        int right=solve(grid,i,j+1,k-cost,dp);
        int left=solve(grid,i+1,j,k-cost,dp);
        int best=max(right,left);
        if(best==INT_MIN){
            return dp[i][j][k]=INT_MIN;
        }
      
        return dp[i][j][k]= score+best;
        
    
    }
};