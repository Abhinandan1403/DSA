class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mpp;
        for(int i = 0 ; i<s.size() ; i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = t[i];
            }
            else if(mpp[s[i]] != t[i]){
                return false;
            }
        }

        unordered_map<char, char>mpp2;
        for(int i = 0 ; i<t.size() ; i++){
            if(mpp2.find(t[i]) == mpp2.end()){
                mpp2[t[i]] = s[i];
            }
            else if(mpp2[t[i]] != s[i]){
                return false;
            }
        }
        return true ;
    }
};