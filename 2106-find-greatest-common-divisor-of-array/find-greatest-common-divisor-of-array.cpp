class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = INT_MIN, smallest = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            largest = max(largest, nums[i]);
            smallest = min(smallest, nums[i]);
        }
        return __gcd(smallest, largest);
    }
};