class Solution {
private:
    const int MOD = 1e9 + 7;
    int solve(int i, int n, vector<vector<int>>& types, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return 1;
        if (target < 0 || i == n)
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int total = 0;
        for (int j = 0; j <= types[i][0]; j++) {
            int val = j * types[i][1];
            if (target - val < 0)
                break;

            int next = solve(i + 1, n, types, target - val, dp);
            total = (next + total) % MOD;
        }

        return dp[i][target] = total;
    }

public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        return solve(0, n, types, target, dp);
    }
};