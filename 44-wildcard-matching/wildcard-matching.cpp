class Solution {
public:
    bool isMatch(string& s, string& p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }

    bool solve(int idx1, int idx2, string& s, string& p,
               vector<vector<int>>& dp) {
        if (idx1 < 0 && idx2 < 0)
            return true;

        if (idx2 < 0)
            return false;

        if (idx1 < 0) {
            for (int i = 0; i <= idx2; i++) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        bool ans = false;
        if (s[idx1] == p[idx2]) {
            ans = solve(idx1 - 1, idx2 - 1, s, p, dp);
        }

        else if (p[idx2] == '*') {
            ans = solve(idx1, idx2 - 1, s, p, dp) ||
                  solve(idx1 - 1, idx2, s, p, dp);
        }

        else if (p[idx2] == '?') {
            ans = solve(idx1 - 1, idx2 - 1, s, p, dp);
        }

        else {
            ans = false;
        }

        return dp[idx1][idx2] = ans;
    }
};