class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        if (vis[node] == 0) {
            vis[node] = 1;
        }

        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int provinces = 0;
        // dfs
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(adj, vis, i);
                provinces++;
            }
        }
        return provinces;
    }
};