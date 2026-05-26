class Solution {
public:
    bool checkValidString(string s) {
        int a = 0;
        for(char c:s){
            if(c=='(' || c=='*')a++;
            else a--;
            if(a<0)return 0;
        }
        a=0;
        reverse(s.begin(),s.end());

        for(char c:s){
            if(c==')' || c=='*')a++;
            else a--;
            if(a<0)return 0;
        }

        return 1;
    }
};