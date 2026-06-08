class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;

        for(int x : nums) {
            if(x < pivot) less++;
            else if(x == pivot) equal++;
        }

        vector<int> ans(nums.size());

        int i = 0;
        int j = less;
        int k = less + equal;

        for(int x : nums) {
            if(x < pivot)
                ans[i++] = x;
            else if(x == pivot)
                ans[j++] = x;
            else
                ans[k++] = x;
        }

        return ans;
    }
};