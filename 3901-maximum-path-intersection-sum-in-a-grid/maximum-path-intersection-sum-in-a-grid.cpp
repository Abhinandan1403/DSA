class Solution {
public:
    int maxScore(vector<vector<int>>& a) { 
        int m=a.size(),n=a[0].size();
        int ans=-1e8;
        for(int i=1;i+1<m;i++){
            for(int j=1;j+1<n;j++){
                ans = max(ans,a[i][j]);
            }
        }            
        for(int i=0;i<m;i++){
            int sum = a[i][0] + a[i][1];
            int max_sum = sum;

            for(int j=2;j<n;j++){
                sum = max(sum + a[i][j], a[i][j-1] + a[i][j]);
                max_sum = max(max_sum, sum);
            }

            ans = max(ans, max_sum);
        }
        for(int j=0;j<n;j++){
            int sum = a[0][j] + a[1][j];
            int max_sum = sum;

            for(int i=2;i<m;i++){
                sum = max(sum + a[i][j], a[i-1][j] + a[i][j]);
                max_sum = max(max_sum, sum);
            }

            ans = max(ans, max_sum);
        }
        return ans;
    }
};

