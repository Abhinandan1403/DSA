class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, text1, text2, dp);
    }

    int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp){
        if(idx1<0 || idx2<0)return 0 ;

        if(dp[idx1+1][idx2+1]!=-1)return dp[idx1+1][idx2+1];

        if(text1[idx1] == text2[idx2]){
            return dp[idx1+1][idx2+1] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
        }

        return dp[idx1+1][idx2+1] = max(solve(idx1, idx2-1, text1, text2, dp), solve(idx1-1, idx2, text1, text2, dp));
    }
};