class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int MOD = 1e9+7 ;
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1, -1);
        int maxD = 0 ;
        dfs(1, vis, adj, 0, maxD);
        int ans = 1;
        for(int i = 1 ; i<maxD ; i++){
            ans = (ans*2)%MOD;
        }
        return ans ;
    }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int depth, int& maxD){
        vis[node] = 1 ;
        maxD = max(maxD, depth);

        for(auto& ngb : adj[node]){
            if(vis[ngb] == -1){
                dfs(ngb, vis, adj, depth+1, maxD);
            }
        }
    }
};