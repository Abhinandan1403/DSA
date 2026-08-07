class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(nums[i]>0){
                st.push(nums[i]);
            }
            else{
                if(!st.empty() && st.top()<0){
                    st.push(nums[i]);
                    continue;
                }

                while(!st.empty() && st.top()>0 && st.top()<abs(nums[i])){
                    st.pop();
                }

                if(!st.empty() && st.top()>0 && st.top() == abs(nums[i])){
                    st.pop();
                    continue;
                }

                else if(!st.empty() && st.top() > abs(nums[i])){
                    continue;
                }

                st.push(nums[i]);
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};