class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        for(auto ch : t){
            mpp[ch]--;
            if(mpp[ch]<0)return false;
            if(mpp[ch] == 0)mpp.erase(ch);
        }
        return !mpp.size();
    }
};