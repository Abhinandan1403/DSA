class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length() ;
        int l = 0 , r = 0 ;
        int count = 0 ;
        unordered_map<char,int>mpp;

        for(r = 0 ; r<n ; r++){
            mpp[s[r]]++;
            if(mpp.size()==3){
                count+=(n-r);
            }
            while(l<r && mpp.size()==3){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                if(mpp.size()==3)count+=(n-r);
                l++;
            }
        }
        return count ;
    }
};