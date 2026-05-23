class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        // return solve(prices, dp, 0, 0);

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buy = 0 ; buy<2 ; buy++ ){
                if(buy == 0){
                    int buyed = -prices[idx] + dp[idx+1][1];
                    int notBuyed = dp[idx+1][0];
                    dp[idx][buy] = max(buyed,notBuyed);
                }
                else{
                    int selled = prices[idx] + dp[idx+1][0] ;
                    int notSelled = dp[idx+1][1];
                    dp[idx][buy] = max(selled,notSelled);
                }
            }
        }

        return dp[0][0];
    }

    // int solve(vector<int>& prices, vector<vector<int>>& dp, int idx, int buy){
    //     if(idx == prices.size()){
    //         return 0 ;
    //     }

    //     if(dp[idx][buy]!=-1){
    //         return dp[idx][buy];
    //     }

    //     if(buy == 0){
    //         int buyed = -prices[idx] + solve(prices, dp, idx+1, 1);
    //         int notBuyed = solve(prices, dp, idx+1, 0);
    //         dp[idx][buy] = max(buyed,notBuyed);
    //     }
    //     else{
    //         int selled = prices[idx] + solve(prices, dp, idx+1, 0);
    //         int notSelled = solve(prices, dp, idx+1, 1);
    //         dp[idx][buy] = max(selled,notSelled);
    //     }

    //     return dp[idx][buy] ; 
    // }
};