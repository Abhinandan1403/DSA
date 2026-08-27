class Solution {
public:
    string minWindow(string s, string t){
        if(t.size()>s.size())return "";
        unordered_map<char, int>mpp;
        int n = t.size();
        for(int i = 0 ; i<n ; i++){
            mpp[t[i]]++;
        }
        int mini = INT_MAX;
        int l = 0;
        int si = 0;
        int count = 0;
        for(int i = 0 ; i<s.size() ; i++){
            mpp[s[i]]--;
            if(mpp[s[i]]>=0){
                count++;
            }


            while(count == n){ 
                if(count == n && mini > i-l+1){
                    si = l;
                    mini = min(mini, i-l+1);
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>=1){
                    count--;
                }
                l++;
            }
        }

        string res = "";
        if(mini == INT_MAX){
            return "";
        }
        res = s.substr(si, mini);
        return res;
    }
};