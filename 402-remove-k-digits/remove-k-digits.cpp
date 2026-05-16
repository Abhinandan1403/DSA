class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        for(int i = 0 ; i<num.size() ; i++){
            if(s.empty()){
                s.push(num[i]);
                continue;
            }
            if(s.top()>num[i]){
                while(k>0 && !s.empty() && s.top()>num[i]){
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
            else{
                s.push(num[i]);
            }
        }

        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }

        if(s.empty())return "0";

        string res = "";
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }

        while(!res.empty() && res.back()=='0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res == "" ? "0" : res ;
    }
};