class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0 ;
        long long maxi = INT_MIN , mini = INT_MAX ;
        for(int i = 0 ; i<nums.size() ; i++ ){
            maxi = max((long long)nums[i], maxi);
            mini = min((long long)nums[i], mini);
        }
        return (maxi-mini)*k;
    }
};