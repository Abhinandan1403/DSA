class Solution {
public:
    vector<pair<int, int>>dirc = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int longestIncreasingPath(vector<vector<int>>& nums) {
        int ans = 1 ;
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums[0].size(), -1));
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = 0 ; j<nums[0].size() ; j++){
                ans = max(ans, solve(nums, i, j, dp));
            }
        }
        return ans ;
    }

    int solve(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& dp){

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 1 ;
        for(int d = 0 ; d<4 ; d++){
            int x = i + dirc[d].first, y = j + dirc[d].second ;
            if(x>-1 && y>-1 && x<nums.size() && y<nums[0].size() && nums[x][y]<nums[i][j]){
                ans = max(ans, 1 + solve(nums, x, y, dp));
            }
        }
        return dp[i][j] = ans;
    }
};