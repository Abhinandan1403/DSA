class Solution {
public:
    typedef pair<int, int> P;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>dist(n+1, 1e9);
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto& it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({1e9, 1});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int distTillNode = it.first;
            int node = it.second;

            for(auto& [ngb, d] : adj[node]){
                int val = min(d, distTillNode);
                if(dist[ngb]==1e9 || dist[ngb]>val){
                    dist[ngb]=val;
                    pq.push({val, ngb});
                }
            }
        }

        int mini = INT_MAX;
        vector<bool>vis(n+1, false);
        dfs(1, mini, adj, vis);


        return dist[n] == 1e9 ? -1 : mini;
    }

    void dfs(int node, int& mini, vector<vector<pair<int, int>>>& adj, vector<bool>& vis){

        vis[node]=1;

        for(auto& [ngb, d] : adj[node]){
            mini = min(mini, d);
            if(!vis[ngb]){
                dfs(ngb, mini, adj, vis);
            }
        }

        return ;
    }
};