class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }

    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx >= nums.size()-1)return 0;

        if(dp[idx]!=-1)return dp[idx];

        int mini = 1e8 ;
        for(int i = 1 ; i<=nums[idx]; i++){
            int steps = 1 + solve(nums, idx+i, dp);
            mini = min(mini, steps);
        }

        return dp[idx] = mini ;
    }
};