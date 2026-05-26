class Solution {
public:
    bool checkValidString(string s) {
        stack<int>s1, s2;
        int cnt = 0 ;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i] == '('){
                s1.push(i);
            }
            else if(s[i] == '*'){
                s2.push(i);
            }
            else{
                if(!s1.empty()){
                    s1.pop();
                }
                else if(!s2.empty()){
                    s2.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(s1.size() == 0)return true;

        while(s1.size()){
            if(s2.empty()){
                return false;
            }
            else if(s1.top()>s2.top()){
                return false;
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        return s1.size() == 0;
    }
};