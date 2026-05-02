class Solution {
public:
    int rotatedDigits(int n) {
        unordered_set<char> c = {'2', '5', '6', '9'};
        unordered_set<char> nc = {'3', '4', '7'};
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string num = to_string(i);
            bool valid = false;
            for (int j = 0; j < num.size(); j++) {
                if (nc.find(num[j]) != nc.end()) {
                    valid = false;
                    break;
                } else if (c.find(num[j]) != c.end()) {
                    valid = true;
                }
            }
            if (valid) {
                ans++;
            }
        }
        return ans;
    }
};