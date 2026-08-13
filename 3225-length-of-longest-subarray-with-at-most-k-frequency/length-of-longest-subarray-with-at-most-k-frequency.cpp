class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        unordered_map<int, int>mpp;
        int maxF = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
            maxF = max(maxF, mpp[nums[i]]);

            while(maxF>k){
                mpp[nums[l]]--;
                l++;
                int f = 0;
                for(auto& it : mpp){
                    f = max(f, it.second);
                }
                maxF = f;
            }

            ans = max(ans, i-l+1);
        }
        return ans;
    }
};