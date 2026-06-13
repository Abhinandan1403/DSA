class Solution {
    typedef long long ll;
    typedef pair<ll, int> pli; 
    int MOD = 1e9 + 7;
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, ll>>> adj(n);
        for(auto& it : roads){
            int u = it[0];
            int v = it[1];
            ll time = it[2]; 
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        vector<ll> dist(n, LLONG_MAX);
        vector<int> count(n, 0);
        
        dist[0] = 0;
        count[0] = 1;
        
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0}); 

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();    
            ll d = it.first;
            int node = it.second;
            if (d > dist[node]) continue;

            for(auto& ngb : adj[node]){
                int ngbNode = ngb.first;
                ll wt = ngb.second;

                if(wt + d < dist[ngbNode]){
                    dist[ngbNode] = wt + d;
                    count[ngbNode] = count[node]; 
                    pq.push({wt + d, ngbNode});
                }
                else if(wt + d == dist[ngbNode]){
                    count[ngbNode] = (count[ngbNode] + count[node]) % MOD; 
                }
            }
        }
        return count[n-1];
    }
};