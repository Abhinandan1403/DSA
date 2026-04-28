class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        int mid = (m * n) / 2;
        vector<int> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int ele = v[mid];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(grid[i][j] - ele);
                if (val % x != 0)
                    return -1;
                else {
                    ans += (val / x);
                }
            }
        }
        return ans;
    }
};