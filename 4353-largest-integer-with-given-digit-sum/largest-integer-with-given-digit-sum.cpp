class Solution {
public:
    int largestInteger(int n, int s) {
        if(n==0)return 0;
        if(n*9<s)return -1;

        string ss = "";
        int nines = s/9;
        for(int i = 0 ; i<nines ; i++){
            ss+='9';
        }
        n-=nines;
        if(s%9){
            int val = s%9;
            char ch = val+'0';
            ss+=ch;
            n--;
        }
        
        while(n!=0){
            ss+='0';
            n--;
        }
        return stoi(ss);
    }
};