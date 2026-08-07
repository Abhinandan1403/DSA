class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp;
        stack<int>st;
        for(int i = nums2.size()-1; i>=0 ; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            mpp[nums2[i]] = (st.empty() ? -1 : st.top());
            st.push(nums2[i]);
        }

        vector<int>res;
        for(auto& num : nums1){
            res.push_back(mpp[num]);
        }
        return res;
    }
};