class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = INT_MIN ;
        unordered_map<int, int>mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            maxi = max(nums[i], maxi);
            mpp[nums[i]]++;
        }

        for(int i = 1 ; i<=maxi ; i++){
            if(i == maxi && mpp[i] != 2){
                return false;
            }
            else if(i<maxi && mpp[i] != 1){
                return false ;
            }
        }
        return true;
    }
};