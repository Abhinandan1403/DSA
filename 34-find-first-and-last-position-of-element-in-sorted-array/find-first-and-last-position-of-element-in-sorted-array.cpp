class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin() ;
        if(idx == nums.size())return {-1, -1};
        if(nums[idx] != target)return {-1, -1};
        int lidx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() ;
        return {idx, lidx-1};
    }
};