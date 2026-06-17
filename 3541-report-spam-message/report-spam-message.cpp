class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st;
        for(auto& it : bannedWords){
            st.insert(it);
        }
        int cnt = 0 ;
        for(auto& it: message){
            if(st.find(it) != st.end()){
                cnt++;
            }
            if(cnt==2)return true;
        }
        return false;
    }
};