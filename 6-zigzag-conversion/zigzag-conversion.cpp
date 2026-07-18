class Solution {
public:
    string convert(string s, int numRows) {
        unordered_map<int, string>mpp;
        int level = 0, up = 1;
        for(int i = 0 ; i<s.size() ; i++){
            if(up == 1){
                mpp[level].push_back(s[i]);
                level++;
            }
            else if(up==0){
                mpp[level].push_back(s[i]);
                level--;
            }

            if(level == numRows){
                level = numRows-2;
                if(level<0){
                    level=0;
                }
                up=0;
            }
            else if(level == -1){
                level = 1;
                if(numRows==1){
                    level=0;
                }
                up=1;
            }
        }
        string ans = "";
        for(int i = 0 ; i<numRows ; i++){
            ans+=(mpp[i]);
        }
        return ans;
    }
};