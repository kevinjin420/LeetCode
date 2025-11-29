class Solution {
public:
    string reverseWords(string s) {
        string res;
        istringstream is(s);
        string word;
        while(is >> word){
            res = " " + word + res;
        }
        res.erase(0, 1);
        return res;
    }
};