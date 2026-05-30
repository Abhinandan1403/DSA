class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1 ;

        while(s<=e){
            int mid = s + (e-s)/2 ;
            if(solve(nums, k, mid)){
                ans = mid ;
                e = mid - 1 ;
            }
            else{
                s = mid+1 ;
            }
        }
        return ans;
    }

    bool solve(vector<int>& nums, int k, int mid){
        int grp = 0 ;
        int sum = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(sum+nums[i]<=mid){
                sum = sum + nums[i] ;
            }
            else{
                grp++;
                sum = nums[i];
            }
        }
        grp++;

        return grp > k ? false : true ;
    }
};