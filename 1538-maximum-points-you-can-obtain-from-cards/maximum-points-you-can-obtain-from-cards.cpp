class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = n-1 ; i>=n-k ; i--){
            sum += nums[i];
            ans = max(ans, sum);
        }

        for(int i = 0 ; i<k ; i++){
            sum += nums[i];
            sum -= nums[n-k+i];
            ans = max(ans, sum);
        }
        return ans;
    }
};