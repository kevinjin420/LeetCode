class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
        int prepre = 2;
        int pre = 3;
        int cur = 0;
        for(int i = 3; i < n; i++){
            cur = pre + prepre;
            prepre = pre;
            pre = cur;
        }
        return cur;
    }
};