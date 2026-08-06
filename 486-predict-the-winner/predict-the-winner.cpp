class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size()-1, sum1 = 0, sum2 = 0;
        return solve(i, j, sum1, sum2, nums, 1);
    }

    bool solve(int i, int j, int sum1, int sum2, vector<int>& nums, int chance){
        if(i>j){
            if(sum1>=sum2){
                return true;
            }
            return false;
        }

        if(chance){
            return solve(i+1, j, sum1+nums[i], sum2, nums, !chance) || solve(i, j-1, sum1+nums[j], sum2, nums, !chance);
            
        }
        else{
            return solve(i+1, j, sum1, sum2+nums[i], nums, !chance) && solve(i, j-1, sum1, sum2+nums[j], nums, !chance); 
        }
    }
};