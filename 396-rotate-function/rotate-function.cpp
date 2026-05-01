class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 , sum = 0 ; 
        int res = 0 ;
        for(int i = 0 ; i<n ; i++){
            res+=(i*nums[i]);
            sum+=nums[i];
        }

        ans = res ;
        for(int i = n-1 ; i>=0 ; i--){
            res = res + sum - ((n)*nums[i]);
            ans = max(ans, res);
        }
        return ans ;
    }
};