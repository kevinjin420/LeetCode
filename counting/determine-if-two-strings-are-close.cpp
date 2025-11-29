class Solution {
public:
    bool closeStrings(string word1, string word2) {
        std::vector<int> s1(26, 0);
        std::vector<int> s2(26, 0);
        for(char c : word1){
            s1[c - 'a']++;
        }
        for(char c : word2){
            s2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if((s1[i] == 0 && s2[i] != 0) || (s2[i] == 0 && s1[i] != 0)){
                return false;
            }
        }
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
};