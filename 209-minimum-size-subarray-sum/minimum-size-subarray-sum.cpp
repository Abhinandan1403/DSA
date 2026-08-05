class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;

        for(int i = 0 ; i<n ; i++){
            sum+=nums[i];
            while(sum>=target){
                ans = min(ans, i-s+1);
                sum-=nums[s];
                s++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};