class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = numeric_limits<int>::min();
        int curr = 0;
        for(int n : nums){
            curr += n;
            res = max(res, curr);
            if(curr < 0) curr = 0;
        }
        return res;
    }
};