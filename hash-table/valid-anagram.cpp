class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(char c : s){
        m1[c]++;
        }
        for(char c : t){
        m2[c]++;
        }
        if(m1.size() != m2.size()){
        return false;
        }
        for(char c : s){
            if(m1[c] != m2[c]){
                return false;
            }
        }
        return true;
    }
};