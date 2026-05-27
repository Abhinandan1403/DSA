class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mpp;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                mpp[word[i]] = i;
            }
            else {
                if (mpp.find(word[i]) == mpp.end()) {
                    mpp[word[i]] = i;
                }
            }
        }

        int ans = 0;

        for (auto it : mpp) {
            char ch = it.first;
            if (ch >= 'a' && ch <= 'z') {
                char upper = ch - 'a' + 'A';
                if (mpp.find(upper) != mpp.end() &&
                    mpp[ch] < mpp[upper]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};