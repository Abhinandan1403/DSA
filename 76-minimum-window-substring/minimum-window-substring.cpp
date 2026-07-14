class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mpp;
        for(auto& ch : t){
            mpp[ch]++;
        }
        int minIdx = -1, minLen = INT_MAX, l = 0, count = 0;

        for(int r = 0 ; r<s.size() ; r++){
            mpp[s[r]]--;
            if(mpp[s[r]]>=0){
                count++;
            }

            if(count == t.size()){
                while(l<=r && count==t.size()){
                    if(minLen>r-l+1){
                        minLen = r-l+1;
                        minIdx = l;
                    }
                    mpp[s[l]]++;
                    if(mpp[s[l]]>0)count--;
                    l++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minIdx, minLen);
    }
};