class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 , depth = 0 ;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == '(')depth++;
            else if(s[i] == ')')depth--;
            // else if(isdigit(s[i])){
            //     ans = max(ans, depth);
            // }
            ans = max(depth, ans);
        }
        return ans ;
    }
};