class Solution {
public:
    vector<int>dirc={0, 1, 0, -1, 0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int s = 0, e = n*n;
        int ans = -1 ;
        while(s<=e){
            int mid = s+(e-s)/2;
            vector<vector<int>>vis(n, vector<int>(n, 0));
            solve(mid, 0, 0, grid, vis);
            if(grid[0][0]<=mid && vis[n-1][n-1]){
                ans = mid;
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    void solve(int mid, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();


        vis[i][j]=1;
        for(int k = 0 ; k<4 ; k++){
            int newi = i+dirc[k], newj = j+dirc[k+1];
            if(newi>=0 && newj>=0 && newi<n && newj<n && grid[newi][newj]<=mid && vis[newi][newj]==0){
                solve(mid, newi, newj, grid, vis);
            }
        }

        return ;
    }
};