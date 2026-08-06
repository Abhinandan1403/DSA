class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j])
                     dp[i+1][j+1] = 1 + dp[i][j];

                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[m][n];
        // return solve(m-1, n-1, s1, s2, dp);
    }

    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(solve(i - 1, j, s1, s2, dp),
                              solve(i, j - 1, s1, s2, dp));
    }
};