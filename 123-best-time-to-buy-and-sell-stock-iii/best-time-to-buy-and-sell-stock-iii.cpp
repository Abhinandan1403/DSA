class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        return solve(0, 2, 1, prices, dp);
    }

    int solve(int i, int k, int flag, vector<int>& p,
              vector<vector<vector<int>>>& dp) {
        if (i == p.size() || k == 0) {
            return 0;
        }
        if (dp[i][k][flag] != -1)
            return dp[i][k][flag];
        int ans = 0;
        if (flag) {
            ans = max(-p[i] + solve(i + 1, k, !flag, p, dp),
                      solve(i + 1, k, flag, p, dp));
        } else {
            ans = max(p[i] + solve(i + 1, k - 1, !flag, p, dp),
                      solve(i + 1, k, flag, p, dp));
        }
        return dp[i][k][flag] = ans;
    }
};