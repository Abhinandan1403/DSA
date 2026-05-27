class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeros = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==0)zeros++;
        }
        if(zeros == nums.size())return 0 ;
        int t = 0 ;
        for(int i = nums.size()-1 ; i>=nums.size()-zeros ; i--){
            if(nums[i]==0)t++;
        }
        return zeros-t;
    }
};