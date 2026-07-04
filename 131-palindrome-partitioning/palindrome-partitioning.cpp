class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(s, 0, ans, v);
        return ans;
    }

    void solve(string &s, int idx, vector<vector<string>>& ans, vector<string>& v){
        if(idx == s.size()){
            ans.push_back(v);
            return;
        }

        string p = "";
        for(int i = idx ; i<s.size() ; i++){
            p+=s[i];
            if(isP(p)){
                v.push_back(p);
                solve(s, i+1, ans, v);
                v.pop_back();
            }
        }
        return;
    }

    bool isP(string& p){
        int i = 0 , j = p.size()-1;
        while(i<=j){
            if(p[i]!=p[j])return false;

            i++;
            j--;
        }
        return true;
    }
};