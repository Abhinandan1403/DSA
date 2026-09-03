class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        for(int i = 0 ; i < nums1.size() ; i++){
            if(nums1[i] % 2){
                mini = min(mini, nums1[i]);
            }
        }

        if(mini == INT_MAX)return 1;

        for(int i = 0 ; i<nums1.size(); i++){
            if(nums1[i] % 2 == 0 && nums1[i] < mini){
                return 0;
            }
        }
        return 1;
    }
};