class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        return solve(0, -1, nums, dp);
    }
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            return 0;
        }
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
        int l = solve(idx + 1, prev, nums, dp);
        if (prev == -1 || nums[idx] > nums[prev]) {
            l = max(l, 1 + solve(idx + 1, idx, nums, dp));
        }
        return dp[idx][prev + 1] = l;
    }
};