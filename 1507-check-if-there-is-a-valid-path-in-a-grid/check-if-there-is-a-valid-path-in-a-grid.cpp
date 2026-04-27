class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},   
        {{-1,0},{1,0}},   
        {{0,-1},{1,0}},   
        {{0,1},{1,0}},    
        {{0,-1},{-1,0}},  
        {{0,1},{-1,0}}    
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(0, 0, grid, vis);
    }

    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int m = grid.size(), n = grid[0].size();

        if(i == m-1 && j == n-1) return true;

        vis[i][j] = 1;

        for(auto d : dirs[grid[i][j]]) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj])
                continue;

            for(auto back : dirs[grid[ni][nj]]) {
                if(ni + back[0] == i && nj + back[1] == j) {
                    if(dfs(ni, nj, grid, vis)) return true;
                }
            }
        }
        return false;
    }
};