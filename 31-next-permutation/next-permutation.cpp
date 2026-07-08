class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n-1;
        while(idx>0){
            if(nums[idx-1]>=nums[idx]){
                idx--;
            }
            else{
                break;
            }
        }
        if(idx == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int val = nums[idx-1];
        int mini = nums[idx];
        int nIdx = idx ;
        for(int i = idx ; i<n ; i++){
            if(nums[i]>val && nums[i]<=mini){
                nIdx = i;
                mini= nums[i];
                nIdx=i;
            }
        }

        swap(nums[idx-1], nums[nIdx]);

        reverse(nums.begin()+idx, nums.end());
        return ;
    }
};