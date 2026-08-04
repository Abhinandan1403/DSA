class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            maxi=max(maxi, nums[i]);
            mini=min(mini, nums[i]);
            st.insert(nums[i]);
        }
        vector<int>v;
        for(int i = mini ; i<=maxi ; i++){
            if(st.find(i) == st.end())v.push_back(i);
        }
        return v;
    }
};