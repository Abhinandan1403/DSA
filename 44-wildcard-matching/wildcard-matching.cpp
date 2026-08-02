class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+2, vector<int>(m+2, -1));
        return solve(s, p, n - 1, m - 1, dp);
    }

    bool solve(string& s, string& p, int n, int m, vector<vector<int>>& dp) {
        if (m == -1 && n != -1)
            return false;
        if (n == -1) {
            for (int i = 0; i <= m; i++) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

        if(dp[n][m] != -1)return dp[n][m];

        else if (p[m] == '?') {
            dp[n][m] = solve(s, p, n - 1, m - 1, dp);
        }

        else if (p[m] == '*') {
            dp[n][m] = solve(s, p, n-1, m, dp) || solve(s, p, n, m-1, dp);
        }

        else if(s[n] == p[m]){
            dp[n][m] = solve(s, p, n-1, m-1, dp);
        }

        else{
            dp[n][m] = false;
        }

        return dp[n][m];
    }
};