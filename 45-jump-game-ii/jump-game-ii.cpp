class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(nums, 0, dp);
    }

    int f(vector<int>& nums, int idx, vector<int>& dp){
        int n = nums.size();

        if(idx >= n-1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;

        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i < n){
                int sub = f(nums, idx + i, dp);

                if(sub != INT_MAX){
                    ans = min(ans, 1 + sub);
                }
            }
        }

        return dp[idx] = ans;
    }
};