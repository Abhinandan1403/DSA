class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string st = s+s;
        for(int i = 0 ; i<n ; i++){
            string get = st.substr(i, n);
            if(get == goal)return true;
        }
        return false ;
    }
};