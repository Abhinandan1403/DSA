class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            v.push_back(nums[i]);
        }
        v.push_back(1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        return solve(1, n, v, dp);
    }

    int solve(int s, int e, vector<int>& v, vector<vector<int>>& dp){
        if(s>e)return 0;

        if(dp[s][e]!=-1)return dp[s][e];

        int ans = INT_MIN;
        for(int i = s ; i<=e ; i++){
            ans = max(ans, v[s-1]*v[e+1]*v[i] + solve(s, i-1, v, dp) + solve(i+1, e, v, dp));
        }
        return dp[s][e] = ans;
    }
};