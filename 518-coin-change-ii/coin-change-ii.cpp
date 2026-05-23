class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1, vector<int>(n+1, -1));
        return solve(amount, coins, 0, dp);
    }

    int solve(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp){
        if(idx == coins.size()){
            return 0 ;
        }

        if(amount == 0){
            return 1;
        }

        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }

        int pick = 0 ;
        if(coins[idx]<=amount){
            pick = solve(amount-coins[idx], coins, idx, dp);
        }
        int notPick = solve(amount, coins, idx+1, dp);

        return dp[amount][idx] = pick+notPick;
    }
};