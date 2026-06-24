class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res = "";
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i]==' ')continue;
            int j = i ;
            while(j+1<s.length() && s[j+1]!=' '){
                j++;
            }
            string val = s.substr(i, j-i+1);
            reverse(val.begin(), val.end());
            res+=val;
            res+=' ';
            i = j+1 ;
        }

        int siz = res.length();
        return res.substr(0, siz-1);
    }
};