class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n, 0);
        map<pair<int, vector<int>>, int>mpp;
        return solve(nums, vis, n, 1, mpp);
    }

    int solve(vector<int>& nums, vector<int>& vis, int& n, int opr, map<pair<int, vector<int>>, int>& mpp){
        
        if(mpp[{opr, vis}])return mpp[{opr, vis}];

        int ans = 0 ;
        for(int i = 0 ; i<n-1 ; i++){
            if(vis[i])continue;
            else vis[i]=1;
            for(int j = i+1 ; j<n ; j++){
                if(vis[j])continue;
                else{
                    vis[j]=1;
                    int first = nums[i], second = nums[j];
                    int val = __gcd(first, second)*opr;

                    ans = max(ans, val+solve(nums, vis, n, opr+1, mpp));

                    vis[j]=0;
                }
            }
            vis[i]=0;
        }
        return mpp[{opr, vis}] = ans;
    }
};