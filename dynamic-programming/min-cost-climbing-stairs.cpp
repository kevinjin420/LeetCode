class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, 0);
        memo[1] = cost[0];
        for(int i = 2; i < memo.size(); i++){
            memo[i] = min(memo[i-1], memo[i-2]) + cost[i-1];
        }
        return min(memo[memo.size() - 2], memo.back());
    }
};