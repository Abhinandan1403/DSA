class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(isConnected[i][j] && i!=j ){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n, 0);
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }

    void dfs(int& node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;

        for(auto& ngb : adj[node]){
            if(!vis[ngb]){
                dfs(ngb, adj, vis);
            }
        }
        return;
    }
};