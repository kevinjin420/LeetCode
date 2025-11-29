class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size();
        int k = word.size() - numFriends + 1;
        string res = word.substr(0, k);
        for(int i = 1; i < n; ++i){
            string curr = word.substr(i, min(k, n - i));
            res = max(res, curr);
        }
        return res;
    }
};