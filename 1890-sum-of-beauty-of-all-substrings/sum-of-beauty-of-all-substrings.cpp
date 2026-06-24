class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            for (int j = i; j < n; j++) {
                v[s[j] - 'a']++;
                int maxi = INT_MIN, mini = INT_MAX;
                for (int z = 0; z < 26; z++) {
                    if (v[z] > 0) {
                        maxi = max(maxi, v[z]);
                        mini = min(mini, v[z]);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};