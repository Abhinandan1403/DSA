class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        unordered_map<int, int>mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;

            while(mpp[nums[i]]>k){
                mpp[nums[l]]--;
                l++;
            }

            ans = max(ans, i-l+1);
        }
        return ans;
    }
};