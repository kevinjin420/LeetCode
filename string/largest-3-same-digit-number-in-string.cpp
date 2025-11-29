class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int res = -1;
        for(int i = 0; i <= n - 3; i++) if(num[i] == num[i+1] && num[i+1] == num[i+2]) res = max(res, (num[i] - '0'));
        string r;
        if(res != -1) for(int i = 0; i < 3; i++) r.push_back('0' + res);
        return r;
    }
};