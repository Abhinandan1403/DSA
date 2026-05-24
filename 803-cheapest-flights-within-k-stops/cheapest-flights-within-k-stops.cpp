class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({0, {src, 0}}); // stops,src,dist;
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;

            if (stops > k)
                break;

            for (auto iter : adj[node]) {
                int near = iter.first;
                int moreDist = iter.second;

                if (distance + moreDist < dist[near]) {
                    dist[near] = distance + moreDist;
                    q.push({stops + 1, {near, dist[near]}});
                }
            }
        }

        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};