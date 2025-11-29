class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;
        string res;
        res += s[0];
        res.reserve(s.size());
        int count = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) count++;
            else count = 1;
            if(count < 3) res += s[i];
        }
        return res;
    }
};