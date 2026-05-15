class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>nums2 = nums ;
        reverse(nums2.begin(), nums2.end());
        vector<int>res ;
        for(auto num: nums){
            res.push_back(num);
        }
        for(auto num: nums2){
            res.push_back(num);
        }

        return res;
    }
};