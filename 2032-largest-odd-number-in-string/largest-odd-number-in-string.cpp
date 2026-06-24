class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1 ;
        while(i>=0){
            int digit = num[i]-'0';
            if(digit%2){
                break;
            }
            i--;
        }
        return num.substr(0, i+1);
    }
};