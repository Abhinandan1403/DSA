class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, k, 1, prices, dp); //idx, totalBuys, buy, prices
    }

    int solve(int idx, int total, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(idx == prices.size() || total==0 )return 0;

        if(dp[idx][total][buy]!=-1)return dp[idx][total][buy];

        int ans = 0 ;
        if(buy){
            ans = max(-prices[idx]+solve(idx+1, total, !buy, prices, dp), solve(idx+1, total, buy, prices, dp));
        }
        else{
            ans = max(prices[idx]+solve(idx+1, total-1, !buy, prices, dp), solve(idx+1, total, buy, prices, dp));
        }
        return dp[idx][total][buy] = ans;
    }
};