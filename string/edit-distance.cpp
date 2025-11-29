class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 1; i <= word1.size(); i++) memo[i][0] = i;
        for(int i = 1; i <= word2.size(); i++) memo[0][i] = i;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]) memo[i][j] = memo[i-1][j-1];
                else memo[i][j] = 1 + min({memo[i-1][j-1], memo[i][j-1], memo[i-1][j]});
            }
        }
        return memo[word1.size()][word2.size()];
    }
};