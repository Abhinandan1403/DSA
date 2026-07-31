class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }

        vector<int> dist(n + 1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[k] = 0;
        dist[0] = 0;

        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int d = it.first;

            for (auto x : adj[node]) {
                if (d + x.second < dist[x.first]) {
                    dist[x.first] = d + x.second;
                    pq.push({d + x.second, x.first});
                } else {
                    continue;
                }
            }
        }

        int ans = 0;
        for (auto& num : dist) {
            ans = max(ans, num);
        }

        return ans == 1e9 ? -1 : ans;
    }
};