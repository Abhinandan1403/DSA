class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> sus(n, 0);
        vector<int> vis(n, 0);
        dfs(k, sus, adj, vis);

        vector<int> vis2(n, 0);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (!vis2[i] && !sus[i]) {
                if (dfs2(i, adj, sus, vis2)) {
                    ok = true;
                }
            }
        }

        vector<int> res;
        if (ok) {
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (sus[i] == 0) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }

    void dfs(int node, vector<int>& sus, vector<vector<int>>& adj,
             vector<int>& vis) {
        vis[node] = 1;
        sus[node] = 1;

        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(it, sus, adj, vis);
            }
        }
        return;
    }

    bool dfs2(int node, vector<vector<int>>& adj, vector<int>& sus,
              vector<int>& vis2) {
        vis2[node] = 1;

        for (auto& ngb : adj[node]) {
            if (!vis2[ngb]) {
                if (sus[ngb])
                    return true;
                else {
                    if (dfs2(ngb, adj, sus, vis2))
                        return true;
                }
            }
        }

        return false;
    }
};