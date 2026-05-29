class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins, 0, amount, dp);
        return ans>1e8 ? -1 : ans;
    }

    int solve(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp){
        if(idx == coins.size()){
            if(amount == 0){
                return 0 ;
            }
            else{
                return 1e9 ;
            }
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int take = 1e9 ;
        if(coins[idx]<=amount){
            take = 1 + solve(coins, idx, amount-coins[idx], dp);
        }
        int notTake = solve(coins, idx+1, amount, dp);

        return dp[idx][amount] = min(take, notTake);
    }
};