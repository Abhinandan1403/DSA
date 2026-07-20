class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int>res;
        int size = m*n ;
        k = k % size;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                res.push_back(grid[i][j]);
            }
        }

        for(int i = 0; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                int idx = (m*n-k);
                grid[i][j]=res[idx%size];
                k--;
            }
        }
        return grid;
    }
};