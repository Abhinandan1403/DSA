class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto& ch : s){
            if(ch == ')'){
                if(!st.empty() && st.top() == '(')st.pop();
                else return false;
            } 
            else if(!st.empty() && ch == '}'){
                if(st.top() == '{')st.pop();
                else return false;
            }
            else if(!st.empty() && ch ==']'){
                if(st.top() == '[')st.pop();
                else return false;
            }
            else{
                st.push(ch);
            }
        }
        return st.empty() ? true : false;
    }
};