class Solution {
public:
    int myAtoi(string s) {
        uint64_t index = 0, n = s.size();
        long long res = 0;
        while(s[index] == ' ' && index < n) index++;
        bool neg = false;
        if(s[index] == '-'){
            neg = true;
            index++;
        }
        else if(s[index] == '+') index++;
        while(isdigit(s[index])){
            res = res * 10 + (s[index++] - '0');
            if(!neg && res > INT_MAX) return INT_MAX;
            if(neg && -res < INT_MIN) return INT_MIN;
        } 
        return neg ? (-1 * res) : res;
    }
};