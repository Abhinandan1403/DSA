class Solution {
public:
    vector<vector<int>>res;
    vector<int>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, 0, target);
        return res;
    }

    void solve(vector<int>& candidates, int idx, int& target){
        if(idx == candidates.size()){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }

        if(target<0)return;

        //take
        ans.push_back(candidates[idx]);
        target-=candidates[idx];
        solve(candidates, idx, target);
        target+=candidates[idx];
        ans.pop_back();

        solve(candidates, idx+1, target);

    }
};