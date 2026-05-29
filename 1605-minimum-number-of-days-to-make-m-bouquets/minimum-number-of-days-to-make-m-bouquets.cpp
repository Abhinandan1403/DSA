class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {

        long long val = (long long)m*k , nn = nums.size() ;
        if (val >nn)
            return -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        int s = mini, e = maxi, ans = INT_MAX;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (solve(nums, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            }

            else {
                s = mid + 1;
            }
        }

        return ans;
    }

    bool solve(vector<int>&nums, int m, int k, int mid){
        int total = 0 , consecutiveDay = 0 ;
        for(auto day : nums){
            if(day <= mid){
                consecutiveDay++ ;
            }
            else{
                consecutiveDay=0;
            }

            if(consecutiveDay == k){
                total++ ;
                if(total == m)return true ;
                consecutiveDay = 0 ;
            }
        }
        return false;
    }
};