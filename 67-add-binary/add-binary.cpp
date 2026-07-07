class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int aInd = a.size() - 1, bInd = b.size() - 1;
        int carry = 0;
        
        while(aInd >= 0 || bInd >= 0 || carry > 0) {
            int aValue = (aInd >= 0) ? (a[aInd] - '0') : 0;
            int bValue = (bInd >= 0) ? (b[bInd] - '0') : 0;
            int sum = aValue + bValue + carry;
            
            if(sum % 2 == 1) {
                ans += '1';
                carry = (sum > 1) ? 1 : 0;
            } else {
                ans += '0';
                carry = (sum > 0) ? 1 : 0;
            }

            if(aInd >= 0) aInd--;
            if(bInd >= 0) bInd--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};