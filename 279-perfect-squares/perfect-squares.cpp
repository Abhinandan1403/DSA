class Solution {
public:
    int numSquares(int n) {
        vector<int>sq;
        for(int i = 1 ; i*i<=n ; i++){
            sq.push_back(i*i);
        }

        vector<vector<int>>dp(n+1, vector<int>(sq.size()+1, -1));

        return solve(sq, n, 0, dp);
    }

    int solve(vector<int>& sq, int n, int idx, vector<vector<int>>& dp){
        if(n<0 || idx == sq.size()){
            return 1e7 ;
        }
        if(n == 0){
            return 0 ;
        }

        if(dp[n][idx]!=-1)return dp[n][idx];

        int take = 1 + solve(sq, n-sq[idx], idx, dp);
        int notTake = solve(sq, n, idx+1, dp);

        return dp[n][idx] = min(take, notTake);
    }
};