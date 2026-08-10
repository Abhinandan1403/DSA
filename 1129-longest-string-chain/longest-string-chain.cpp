class Solution {
public:
    bool static comp(string& s1, string& s2) { return s1.size() < s2.size(); }
    int longestStrChain(vector<string>& words) {
        int prev = -1, idx = 0;
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(prev, idx, words, dp);
    }

    int solve(int prev, int idx, vector<string>& words,
              vector<vector<int>>& dp) {
        if (idx == words.size())
            return 0;
        if (dp[prev + 1][idx] != -1)
            return dp[prev + 1][idx];
        if (prev == -1 || isCorrect(words[prev], words[idx])) {
            int take = 1 + solve(idx, idx + 1, words, dp);
            int notTake = solve(prev, idx + 1, words, dp);
            return dp[prev + 1][idx] = max(take, notTake);
        }
        return dp[prev + 1][idx] = solve(prev, idx + 1, words, dp);
    }

    bool isCorrect(string& s1, string& s2) {
        if (s2.length() - s1.length() != 1)
            return false;

        int i = 0, j = 0;
        int count = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;
                count++;
            }
        }
        if (i == s1.size() && j == s2.size() - 1 && count == 0) {
            return true;
        }

        return count == 1 && i == s1.size() && j == s2.size() ? true : false;
    }
};