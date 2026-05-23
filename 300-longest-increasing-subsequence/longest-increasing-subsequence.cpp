class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

        // for(int idx = n-1 ; idx>=0 ; idx--){
        //     for(int prev_idx = idx-1 ; prev_idx>=-1 ; prev_idx--){
        //         int take = 0 ;
        //         if(prev_idx == -1 || nums[prev_idx]<nums[idx]){
        //             take = 1 + dp[idx+1][idx+1];
        //         }

        //         int notTake = dp[idx+1][prev_idx+1];

        //         dp[idx][prev_idx+1] = max(take, notTake);
        //     }
        // }

        // return dp[0][0];

        vector<int>temp;
        for(int i = 0 ; i<n ; i++){
            if(temp.empty() || temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx]=nums[i];
            }
        }

        return temp.size();



        // return solve(nums, 0, -1, dp);
    }

    // int solve(vector<int>& nums, int idx, int prev_idx, vector<vector<int>>& dp){
    //     if(idx == nums.size())return 0 ;

    //     if(dp[idx][prev_idx+1]!=-1)return dp[idx][prev_idx+1];

        // int take = 0 ;
        // if(prev_idx == -1 || nums[prev_idx]<nums[idx]){
        //     take = 1 + solve(nums, idx+1, idx, dp);
        // }

        // int notTake = solve(nums, idx+1, prev_idx, dp);

        // return dp[idx][prev_idx+1] = max(take, notTake);
    // }
};