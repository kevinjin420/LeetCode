class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0) memo[i] = min(memo[i], memo[i-coin] + 1);
            }
        }
        return (memo.back() == amount + 1) ? -1 : memo.back();
    }
};