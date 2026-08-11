class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, ans = 0;
        int maxi = 0;
        vector<int>v(26, 0);
        for(int i = 0 ; i<s.size() ; i++){
            v[s[i]-'A']++;
            maxi = max(maxi, v[s[i]-'A']);
            if(i-l+1-maxi > k){
                v[s[l]-'A']--;
                l++;
            }

            if(i-l+1-maxi <=k){
                ans = max(ans, i-l+1);
            }
        }
        return ans;
    }
};