class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, -1);
        return solve(0, n, s, dp)-1;
    }

    int solve(int ss, int n, string& s, vector<int>& dp){
        if(ss == n)return 0;

        if(dp[ss]!=-1)return dp[ss];

        int ans = INT_MAX;
        for(int i = ss ; i<n ; i++){
            if(isP(ss, i, s)){
                ans = min(ans, 1+solve(i+1, n, s, dp));
            }
        }

        return dp[ss] = ans;
    }

    bool isP(int i, int e, string& s){
        while(i<=e){
            if(s[i]!=s[e])return false;

            i++;
            e--;
        }
        return true;
    }
};