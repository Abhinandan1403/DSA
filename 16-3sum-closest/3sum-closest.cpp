class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i<n ; i++){
            int j = i+1 , k = n-1;
            while(j<k){
                if(abs(nums[i]+nums[j]+nums[k]-target)==0)return target;

                if(abs(nums[i]+nums[j]+nums[k]-target)<diff){
                    diff = abs(nums[i]+nums[j]+nums[k]-target);
                    ans = nums[i]+nums[j]+nums[k];
                }

                int diff1 = abs(nums[i]+nums[j+1]+nums[k]-target);
                int diff2 = abs(nums[i]+nums[j]+nums[k-1]-target);

                if(diff1<diff2){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};