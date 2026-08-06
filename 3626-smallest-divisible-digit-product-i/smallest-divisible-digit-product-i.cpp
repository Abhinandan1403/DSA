class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n ; i<=100 ; i++){
            int val = solve(i);
            if(val % t == 0)return i;
        }
        return -1;
    }

    int solve(int i){
        int res = 1;
        while(i){
            res *= (i%10);
            i /= 10;
        }
        return res;
    }
};