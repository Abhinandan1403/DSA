class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = to_string(n);
        long long x = 0;
        int sum = 0;
        for(int i = 0 ; i<num.size() ; i++){
            if(num[i]!='0'){
                x*=10;
                x+=(num[i]-'0');
                sum+=(num[i]-'0');
            }
        }
        return x*sum;
    }
};