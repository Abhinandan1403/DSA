class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mini = INT_MAX ;
        vector<int>free(n, 0) ;
        vector<vector<int>>dp(n+1, vector<int>(budget+1, -1));
        for(int i = 0 ; i<n ; i++){
            mini = min(items[i][1], mini);
            for(int j = 0 ; j<n ; j++){
                if(i != j){
                    if(items[j][0] % items[i][0] == 0){
                        free[i]++;
                    }
                }
            }
        }

        return solve(items, budget, 0, free, dp, mini);
    }

    int solve(vector<vector<int>>& items, int budget, int idx, vector<int>& free, vector<vector<int>>& dp, int& mini){

        if(idx == items.size()){
            return budget/mini ;
        }

        if(dp[idx][budget] != -1){
            return dp[idx][budget];
        }

        int take = 0 ;
        if(items[idx][1]<=budget){
            take = free[idx] + 1 + solve(items, budget-items[idx][1], idx+1, free, dp, mini);
        }
        int notTk = solve(items, budget, idx+1, free, dp, mini);

        return dp[idx][budget] = max(take, notTk);
    }
};