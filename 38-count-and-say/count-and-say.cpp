class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string ans = "";
        for(int i = 2 ; i<=n ; i++){
            ans = "";
            char ch = prev[0];
            int count = 0;
            int j = 0 ;
            while(j<prev.size()){
                if(prev[j] == ch){
                    count++;
                    j++;
                }

                else{
                    char cnt = count + '0';
                    ans+=cnt;
                    ans+=ch;
                    ch = prev[j];
                    j++;
                    count = 1;
                }
            }
            ans+=(count+'0');
            ans+=prev[j-1];

            prev = ans;
        }
        return prev;
    }
};