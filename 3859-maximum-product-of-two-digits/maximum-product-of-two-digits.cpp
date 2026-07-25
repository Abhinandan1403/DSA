class Solution {
public:
    int maxProduct(int n) {
        int l = -1;
        int l2 = -1;
        while(n){
            int d = n%10;
            if(d>l){
                l2=l;
                l=d;
            }
            else if(d>l2){
                l2 =d;
            }
            n/=10;
        }
        return l*l2;
    }
};