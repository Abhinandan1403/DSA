class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 0);

        for(int idx = nums.size()-1 ; idx>=0 ; idx--){
            int pick = nums[idx] ;
            if(idx+2<nums.size()){
                pick+=dp[idx+2];
            }
            int notPick = INT_MIN ;
            if(idx+1<nums.size()){
                notPick = dp[idx+1];
            }

            dp[idx] = max(pick, notPick);
        }
        return dp[0];

        // return solve(0, nums, dp);
    }

    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size())return 0 ;

        if(dp[idx]!=-1)return dp[idx];

        int pick = nums[idx] + solve(idx+2, nums, dp);
        int notPick = solve(idx+1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }
};