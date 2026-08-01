class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }

    int solve(vector<int>& nums, int k){
        if(k<=0)return 0;

        unordered_map<int,int>mp;
        int cnt=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size()>k){
              mp[nums[l]]--;
              if(mp[nums[l]]==0){
                mp.erase(nums[l]);
              }
              l++;
            }
            
            if(mp.size()<=k){
                cnt+=(r-l+1);
            }
        }
        return cnt;
    }
};