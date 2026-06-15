class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = -1, n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(nums[i]==0){
                idx = i;
                break;
            }
        }
        if(idx == -1)return ;
        for(int i = idx+1 ; i<n ; i++){
            if(nums[i]!=0){
                swap(nums[i], nums[idx]);
                idx++ ;
            }
        }
        return;
    }
};