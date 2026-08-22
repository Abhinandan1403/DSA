class Solution {
public:
    int f1(int n) {
        int sum = 0, prod = 1;
        while (n > 0) {
            sum += n % 10;
            prod *= n % 10;
            n /= 10;
        }
        return sum + prod;
    }
    bool checkDivisibility(int n) {
        int ans = f1(n);
        return n % ans == 0;
    }
};