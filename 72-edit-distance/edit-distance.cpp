class Solution {
public:
    int minDistance(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, s1, s2, dp);
    }

    int solve(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
        if(idx1<0)return idx2+1;
        if(idx2<0)return idx1+1;

        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];

        if(s1[idx1] == s2[idx2]){
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, s1, s2, dp);
        }
        return dp[idx1][idx2] = min({1 + solve(idx1, idx2-1, s1, s2, dp), 1 + solve(idx1-1, idx2, s1, s2, dp), 1 + solve(idx1-1, idx2-1, s1, s2, dp)});
    }
};