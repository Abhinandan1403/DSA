class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0 , j = 0 , ans = 0 ;
        int m = g.size() , n = s.size() ;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<m && j<n){
            if(g[i]<=s[j]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans ;
    }
};