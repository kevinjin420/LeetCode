class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> powers(n, 1);
        for(int i = 1; i < n; i++) powers[i] = (powers[i - 1] * 2) % mod;
        int left = 0, right = n - 1;
        int res = 0;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                res = (res + powers[right - left]) % mod;
                left++;
            }
            else right--;
        }
        return res;
    }
};