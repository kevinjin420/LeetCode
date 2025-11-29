class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int res = 0;
        bool canType = true;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (canType) res++;
                canType = true;
            } else {
                if (broken.count(text[i])) canType = false;
            }
        }
        return res;
    }
};