class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s ;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size(); 
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                int ans = 0 ;

                if(s1[i] == s2[j]){
                    ans = 1 + dp[i+1][j+1] ;
                }
                else{
                    int a = dp[i+1][j];
                    int b = dp[i][j+1];
                    ans = max(a, b);
                }

                dp[i][j] = ans ;
            }
        }

        return dp[0][0] ;

        // return solve(0, 0, s1, s2, dp);
    }

    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i>=s1.size() || j>=s1.size())return 0 ;

        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }

        int ans = 0 ;

        if(s1[i] == s2[j]){
            ans = 1 + solve(i+1, j+1, s1, s2, dp);
        }
        else{
            int a = solve(i+1, j, s1, s2, dp);
            int b = solve(i, j+1, s1, s2, dp);
            ans = max(a, b);
        }

        return dp[i][j] = ans ;
    }
};