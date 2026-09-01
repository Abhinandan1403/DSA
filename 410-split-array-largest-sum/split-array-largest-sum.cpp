class Solution {
private:
    int solve(vector<int>& nums, int k){
        int grp = 0;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum += nums[i];
            if(sum == k){
                grp++;
                sum = 0;
            }
            else if(sum >k){
                grp++;
                sum = nums[i];
            }
        }
        return sum == 0 ? grp : grp + 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {

        if(k > nums.size())return -1;

        int s = 0 , e = 0, n = nums.size();
        for(int i = 0 ; i<n ; i++){
            s = max(s, nums[i]);
            e += nums[i];
        }

        int ans = 0;

        while(s<=e){
            int mid = s + (e-s)/2 ;
            int grp = solve(nums, mid);

            if(grp<=k){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};