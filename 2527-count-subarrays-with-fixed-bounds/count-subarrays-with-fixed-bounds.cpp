class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        unordered_map<int, int>mpp;
        mpp[minK]=-1;
        mpp[maxK]=-1;
        int lastIdx = -1;
        int n = nums.size();
        long long sum = 0;
        for(int r = 0 ; r<n ; r++){
            if(nums[r]>maxK || nums[r]<minK){
                lastIdx=r;
            }
            else if(nums[r]==maxK){
                mpp[maxK]=r;
            }
            else if(nums[r]==minK){
                mpp[minK]=r;
            }

            if(mpp[minK]!=-1 && mpp[maxK]!=-1 && mpp[minK]>lastIdx && mpp[maxK]>lastIdx){
                int mini = min(mpp[maxK], mpp[minK]);
                sum+=(mini-lastIdx);
            }
        }
        return sum;
    }
};