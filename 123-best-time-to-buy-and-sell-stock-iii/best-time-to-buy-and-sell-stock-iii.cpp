class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 0, 0, dp);
    }

    int solve(vector<int>& prices, int idx, int buy, int total, vector<vector<vector<int>>>&dp){
        if(idx == prices.size() || total == 2){
            return 0 ;
        }

        if( dp[idx][buy][total] != -1 ){
            return dp[idx][buy][total];
        }

        int profit = 0 ;

        if(!buy){
            profit = max(solve(prices, idx+1, 0, total, dp), -prices[idx]+solve(prices, idx+1, 1, total, dp));
        }
        else{
            profit = max(solve(prices, idx+1, 1, total, dp), prices[idx]+solve(prices, idx+1, 0, total+1, dp));
        }

        return dp[idx][buy][total] = profit ;
    }
};