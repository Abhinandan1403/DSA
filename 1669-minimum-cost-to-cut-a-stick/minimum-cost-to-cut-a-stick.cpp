class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int s = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int>v;
        v.push_back(0);
        for(auto& num: cuts){
            v.push_back(num);
        }
        v.push_back(n);
        vector<vector<int>> dp(s+2, vector<int>(s+2, -1));
        return solve(1, s, v, dp);
    }

    int solve(int s, int e, vector<int>& v, vector<vector<int>>& dp){
        if(s > e)return 0;

        if(dp[s][e]!=-1)return dp[s][e];

        int ans = INT_MAX ;
        for(int i = s ; i<=e ; i++){
            ans = min(ans, v[e+1]-v[s-1] + solve(s, i-1, v, dp) + solve(i+1, e, v, dp));
        }
        return dp[s][e] = ans;
    }
};