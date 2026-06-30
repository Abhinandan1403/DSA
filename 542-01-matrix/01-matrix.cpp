class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({0, {i, j}});
                }
            }
        }

        vector<int>dirc = {0, 1, 0, -1, 0};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dist = it.first, x = it.second.first, y = it.second.second;
            mat[x][y]=dist;

            for(int i = 0 ; i<4 ; i++){
                int newx = x + dirc[i], newy = y + dirc[i+1];
                if(newx<m && newy<n && newx>=0 && newy>=0 && !vis[newx][newy] && mat[newx][newy]){
                    vis[newx][newy]=1;
                    q.push({dist+1, {newx, newy}});
                }
            }
        }
        return mat;
    }
};