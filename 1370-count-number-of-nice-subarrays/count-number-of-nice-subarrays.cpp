class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }

    int solve(vector<int>& nums, int k){
        if(k<0)return 0;
        int count = 0 ;
        int l = 0, r = 0, ans = 0;
        for( r = 0 ; r<nums.size() ; r++){
            if(nums[r]%2)count++;

            while(count>k){
                if(nums[l]%2){
                    count--;
                }
                l++;
            }

            ans+=(r-l+1);
        }
        return ans;
    }
};