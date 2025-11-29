class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int n = amount;
        vector<vector<uint64_t>> dp(m+1, vector<uint64_t>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1] && dp[i][j-coins[i-1]] != 0) dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
        return dp.back().back();
    }
};