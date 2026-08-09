class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN, sum = 0;
        for (auto& num : nums) {
            maxi = max(num, maxi);
            sum += num;
        }

        if(sum == 0)return 0;

        int s = maxi, e = sum;
        int ans = 1e9;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (solve(nums, mid) <= k) {
                ans = min(ans, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<int>& nums, int m) {
        int n = nums.size();
        int grp = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum == m){
                grp++;
                sum=0;
            }
            else if(sum > m){
                grp++;
                sum = nums[i];
            }
        }
        return sum == 0 ? grp : ++grp;
    }
};