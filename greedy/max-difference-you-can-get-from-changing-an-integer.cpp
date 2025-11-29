class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        char first = n[0];
        set<char> unique(n.begin(), n.end());
        int maxRes = num, minRes = num;
        for(char digit : unique){
            for(char newDigit = '0'; newDigit <= '9'; newDigit++){
                if(digit == first && newDigit == '0') continue;
                string newRes = n;
                replace(newRes.begin(), newRes.end(), digit, newDigit);
                maxRes = max(maxRes, stoi(newRes));
                minRes = min(minRes, stoi(newRes));
            }
        }
        return maxRes - minRes;
    }
};