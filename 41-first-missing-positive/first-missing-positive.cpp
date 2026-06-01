class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = INT_MIN ;
        unordered_set<int>st;

        for(auto num: nums){
            if(num>0){
                st.insert(num);
            }
            maxi = max(maxi, num);
        }

        for(int i = 1 ; i<=max(maxi, 1); i++){
            if(st.find(i) == st.end()){
                return i ;
            }
        }
        return maxi + 1;
    }
};