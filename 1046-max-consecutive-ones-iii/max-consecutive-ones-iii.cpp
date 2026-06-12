class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , maxL = 0, zeros = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            maxL = max(maxL, i-l+1);
        }
        return maxL ;
    }
};