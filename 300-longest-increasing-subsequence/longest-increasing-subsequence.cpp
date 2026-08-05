class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int n = nums.size();
        vector<vector<int>>dp(n+3, vector<int>(n+3, -1));
        return solve(prev, 0, nums, dp);
    }

    int solve(int prev, int idx, vector<int>& nums, vector<vector<int>>& dp){

        if(idx == nums.size())return 0;

        if(dp[prev+1][idx]!=-1) return dp[prev+1][idx];

        int pick = INT_MIN;
        if(prev == -1 || nums[prev]<nums[idx]){
            pick = 1 + solve(idx, idx+1, nums, dp);
        }
        int notPick = solve(prev, idx+1, nums, dp);

        return dp[prev+1][idx] = max(pick, notPick);
    }
};