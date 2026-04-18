class Solution {
public:
    vector<vector<int>>res;
    int n ;
    void solve(vector<int>& temp, unordered_map<int, int>& mpp){
        if(temp.size()==n){
            res.push_back(temp);
        }

        for(auto& it : mpp){
            if(it.second == 0)continue ;

            temp.push_back(it.first);
            mpp[it.first]--;

            solve(temp, mpp);

            temp.pop_back();
            mpp[it.first]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        // sort(nums.begin(), nums.end());
        unordered_map<int, int>mpp ;
        vector<int>temp ;

        for(int i = 0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }

        solve(temp, mpp);
        return res;
    }
};