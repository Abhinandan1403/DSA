class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>>adj(n);
        for(int i = 0 ; i<n ; i++ ){
            for(int j = 0 ; j<n ; j++ ){
                if(i != j){
                    int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                    adj[i].push_back({j, dist});
                }
            }
        }
        vector<int>vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0}); //dist, node
        int ans = 0 ;
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            ans += dist;

            for(auto& ngb : adj[node]){
                int ngbNode = ngb.first;
                int nodeDist = ngb.second;

                if(!vis[ngbNode]){
                    pq.push({nodeDist, ngbNode});
                }
            }
        } 
        return ans ;
    }
};