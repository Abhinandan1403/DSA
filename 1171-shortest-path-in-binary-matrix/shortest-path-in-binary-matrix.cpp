class Solution {
public:
    typedef pair<int,pair<int, int>> pip;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;
        queue<pip>q;
        q.push({1, {0,0}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int ans = -1 ;
        vector<pair<int,int>>dirc = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;

            if(x==n-1 && y==n-1)return dist;

            for(int i = 0 ; i<8 ; i++){
                int newx = x + dirc[i].first;
                int newy = y + dirc[i].second;

                if(newx<n && newx>=0 && newy<n && newy>=0 && grid[newx][newy]==0 && vis[newx][newy]==0){
                    if(newx == n-1 && newy == n-1)return dist+1 ;
                    else{
                        q.push({dist+1, {newx, newy}});
                        vis[newx][newy]=1;
                    }
                }
            }
        }
        return -1 ;
    }
};