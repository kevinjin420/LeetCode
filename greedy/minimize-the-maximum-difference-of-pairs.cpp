class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(nums.empty() || !p) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while(left < right){
            int mid = left + (right - left) / 2;
            int currPairs = 0;
            for(int i = 1; i < n; i++) if(nums[i] - nums[i-1] <= mid) currPairs++, i++;
            if(currPairs >= p) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};