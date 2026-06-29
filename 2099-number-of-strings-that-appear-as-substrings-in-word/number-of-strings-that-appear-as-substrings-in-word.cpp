class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0 ;
        int n = word.size();
        for(auto& p : patterns){
            int len = p.size();
            for(int i = 0 ; i<=n-len ; i++){
                if(word.substr(i, len) == p){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};