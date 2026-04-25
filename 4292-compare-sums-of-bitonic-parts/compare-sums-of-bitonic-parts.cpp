class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long asc = 0 ;
        long long des = 0 ;
        long long maxi = INT_MIN ;

        for(int i = 0 ; i<nums.size() ; i++){
            // maxi = max(maxi, nums[i]);
            if(i == 0)asc += nums[i];
            else if(i == nums.size()-1)des+=nums[i];

            else if(nums[i-1]<=nums[i] && nums[i]<=nums[i+1])asc+=nums[i];
            else if(nums[i-1]>=nums[i] && nums[i]>=nums[i+1])des+=nums[i];
        }

        cout << asc << " "<<des ;

        if(asc == des)return -1;

        return asc>des ? 0 : 1;
    }
};