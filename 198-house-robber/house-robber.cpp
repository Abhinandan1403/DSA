class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(0, nums, dp);
    }

    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size())return 0 ;

        if(dp[idx]!=-1)return dp[idx];

        int pick = nums[idx] + solve(idx+2, nums, dp);
        int notPick = solve(idx+1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }
};