class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        if(!vis[i][j]){
            vis[i][j]=1;
        }
        vector<int>delr = {1,-1,0,0};
        vector<int>delc = {0,0,1,-1};

        for(int a = 0 ; a<4 ; a++){
            int nr = i+delr[a];
            int nc = j+delc[a];

            if(nc>=0 && nc<vis[0].size() && nr>=0 && nr<vis.size() && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(grid, vis, nr, nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size() ;
        vector<vector<int>>vis(m, vector<int>(n, 0));

        int islands = 0 ;
        for(int i = 0; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid, vis, i, j);
                    islands++;
                }
            }
        }
        return islands ;
    }
};