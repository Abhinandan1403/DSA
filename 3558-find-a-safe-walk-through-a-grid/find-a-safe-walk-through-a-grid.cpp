class Solution {
    typedef pair<int, pair<int, int>> p;
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 1e9));
        priority_queue<p, vector<p>, greater<p>>pq;
        vis[0][0]=grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        vector<int>dirc = {0, 1, 0, -1, 0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dist = it.first, x = it.second.first, y = it.second.second;

            for(int i = 0 ; i<4 ; i++){
                int nx = x+dirc[i], ny = y+dirc[i+1];
                if(nx<m && ny<n && nx>=0 && ny>=0 && vis[nx][ny]>dist+grid[nx][ny]){
                    vis[nx][ny]=dist+grid[nx][ny];
                    pq.push({vis[nx][ny], {nx, ny}});
                }
            }
        }

        return health-vis[m-1][n-1]>=1;
    }
};