class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEntry = *max_element(nums.begin(), nums.end());
        int curr = 0;
        int res = 0;
        for(int n : nums){
            if(n == maxEntry) res = max(res, ++curr);
            else curr = 0;
        }
        return res;

    }
};