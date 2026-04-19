class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>big(n);
        vector<int>small(n);
        int val = 0 ;
        for(int i = 0 ; i<n ;i++){
            val = max(val,nums[i]);
            big[i]=val;
        }
        val = INT_MAX;
        for(int i = n-1 ; i>=0 ; i--){
            val = min(val, nums[i]);
            small[i]=val;
        }
        for(int i = 0 ; i<n ; i++){
            if(big[i]-small[i]<=k)return i ;
        }
        return -1;
    }
};