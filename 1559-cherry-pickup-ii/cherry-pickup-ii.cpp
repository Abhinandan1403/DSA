class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int len = grid[0].size();
        int n = grid.size();
        vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(len+1, vector<int>(n+1, -1)));
        return solve(0, len-1, 0, grid, dp);
    }

    int solve(int i, int j, int lvl, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){

        if(lvl == grid.size())return 0 ;

        if(dp[i][j][lvl]!=-1)return dp[i][j][lvl];

        int cherry = 0 ;
        if(i == j){
            cherry += grid[lvl][i];
        }
        else{
            cherry+=(grid[lvl][i] + grid[lvl][j]);
        }
        int ans = 0 ;
        for(int x = -1 ; x<2 ; x++){
            for(int y = -1 ; y<2 ; y++){
                int newi = i+x , newj = j+y ;
                if(newi>=0 && newj>=0 && newi<grid[0].size() && newj<grid[0].size()){
                    int val = cherry + solve(newi, newj, lvl+1, grid, dp);
                    ans = max(ans, val);
                }
            }
        }
        return dp[i][j][lvl] = ans ;
    }
};