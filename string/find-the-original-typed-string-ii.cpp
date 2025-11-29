class Solution {
public:
    int possibleStringCount(string word, int k) {
        int mod = 1e9 + 7;
        vector<int> groups;
        int count = 1;
        for(int i = 1; i < word.size(); i++){
            if(word[i] == word[i-1]) count++;
            else{
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);
        
        long long total = 1;
        for(int n : groups) total = (total * n) % mod;

        if(k <= (int)groups.size()) return total;

        vector<int> memo(k, 0);
        memo[0] = 1;
        for(int n : groups){
            vector<int> newMemo(k, 0);
            long long sum = 0;
            for(int s = 0; s < k; s++){
                if(s > 0) sum = (sum + memo[s - 1]) % mod;
                if(s > n) sum = (sum - memo[s - n - 1] + mod) % mod;
                newMemo[s] = sum;
            }
            memo = newMemo;
        }
        long long inv = 0;
        for(int s = groups.size(); s < k; s++){
            inv = (inv + memo[s]) % mod;
        }
        return (total - inv + mod) % mod;
    }
};