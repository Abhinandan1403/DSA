class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
    }

    int solve(vector<int>& nums, int idx, int prev_idx, vector<vector<int>>& dp){
        if(idx == nums.size())return 0 ;

        if(dp[idx][prev_idx+1]!=-1)return dp[idx][prev_idx+1];

        int take = 0 ;
        if(prev_idx == -1 || nums[prev_idx]<nums[idx]){
            take = 1 + solve(nums, idx+1, idx, dp);
        }

        int notTake = solve(nums, idx+1, prev_idx, dp);

        return dp[idx][prev_idx+1] = max(take, notTake);
    }
};