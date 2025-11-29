class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        istringstream iss(s);
        string w;
        int charPtr = 0;
        while(iss >> w){
            char c = pattern[charPtr];
            if(!c2s.count(c) && !s2c.count(w)){
                c2s[c] = w;
                s2c[w] = c;
            }
            else if(s2c.count(w)){
                if(s2c[w] != c) return false;
            }
            else if(c2s.count(c)){
                if(c2s[c] != w) return false;
            }
            charPtr++;
        }
        return charPtr == pattern.size();
    }
};