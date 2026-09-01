class Solution {
public:
    int solve(int i, int am, vector<int>& coins, vector<vector<int>>& dp) {
        // base case
        if (i == coins.size()) {
            if (am == 0)
                return 1;
            else
                return 0;
        }
        if (dp[i][am] != -1)
            return dp[i][am];
        int pick = 0;
        if (am >= coins[i]) {
            pick = solve(i, am - coins[i], coins, dp);
        }
        int notpick = solve(i + 1, am, coins, dp);
        return dp[i][am] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }
};