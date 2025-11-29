class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr = 0;
        string res;
        while(ptr < word1.size() && ptr < word2.size()){
            res.push_back(word1[ptr]);
            res.push_back(word2[ptr]);
            ptr++;
        }
        if(ptr == word1.size()){
            while(ptr < word2.size()){
                res.push_back(word2[ptr]);
                ptr++;
            }
        }
        else{
            while(ptr < word1.size()){
                res.push_back(word1[ptr]);
                ptr++;
            }
        }
        return res;
    }
};