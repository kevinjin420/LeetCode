class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int sum = 0;
        int carry = 0;
        int aIt = a.length() - 1;
        int bIt = b.length() - 1;
        while(aIt >= 0 || bIt >= 0 || carry){
            int sum = carry;
            if(aIt >= 0){
                sum += a[aIt--] - '0';
            }
            if(bIt >= 0){
                sum += b[bIt--] - '0';
            }
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};