class Solution {
public:
    bool validDigit(int n, int x) {
        string num = to_string(n);
        char ch = x + '0' ;
        cout << ch ;
        if(num[0] == ch)return false ;
        for(int i = 1 ; i<num.size() ; i++){
            if(ch == num[i])return true;
        }
        return false ;
    }
};