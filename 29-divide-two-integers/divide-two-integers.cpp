class Solution {
    typedef long long ll;
public:
    int divide(int dividend, int divisor) {
        ll ans = (ll)dividend/(ll)divisor;
        if(ans>INT_MAX)return (int)INT_MAX;
        return ans;
    }
};