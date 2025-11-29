class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tp = 0;
        int sp = 0;
        while(tp < t.size() && sp < s.size()){
            if(t[tp] == s[sp]){
                sp++;
            }
            tp++;
        }
        return sp == s.size();
    }
};