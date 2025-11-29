class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int max_sum = sum;
        for(int i = 0; i < nums.size() - k; i++){
            sum -= nums[i];
            sum += nums[k + i];
            max_sum = max(max_sum, sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};