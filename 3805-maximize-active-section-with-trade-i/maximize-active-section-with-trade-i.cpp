class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>v;
        int ones = 0, zeros = 0;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]=='1'){
                ones++;
                if(zeros>0){
                    v.push_back(zeros);
                }
                zeros=0;
            }
            else{
                zeros++;
            }
        }
        if(s[s.size()-1]=='0'){
            v.push_back(zeros);
        }

        if(v.size()<2)return ones;
        int maxi = 0;
        for(int i = 0 ; i<v.size()-1 ; i++){
            int first = v[i];
            int second = v[i+1];
            maxi = max(maxi, first+second);
        }
        return maxi+ones;
    }
};