class Solution {
public:
    string smallestPalindrome(string& ss) {
        vector<int>freq(26, 0);
        for(char &ch : ss){
            freq[ch-'a']++;
        }

        string res(ss.length(), ' ');
        int s = 0, e = ss.length()-1, mid = s + (e-s)/2;
        for(int i = 0 ; i<26 ; i++){
            if(freq[i]==0)continue;
            else if(freq[i]==1)res[mid]=i+'a';

            else{
                if(freq[i]%2){
                    int val = freq[i]/2;
                    for(int j = 0 ; j<val ; j++){
                        res[s++]=i+'a';
                        res[e--]=i+'a';
                    }
                    res[mid]=i+'a';
                }
                else{
                    int val = freq[i]/2;
                    for(int j = 0 ; j<val ; j++){
                        res[s++]=i+'a';
                        res[e--]=i+'a';
                    }
                }
            }
        }
        return res;
    }
};