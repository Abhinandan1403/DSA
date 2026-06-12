class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mpp;
        int maxL = 0 , l = 0 ;
        for(int i = 0 ; i<s.size() ; i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = i ;
                maxL = max(maxL, i-l+1 );
            }
            else{
                if(mpp[s[i]]+1 > l){
                    l = mpp[s[i]] + 1;
                }
                mpp[s[i]] = i ;
                maxL = max(maxL, i-l+1);
            }
        }
        return maxL ;
    }
};