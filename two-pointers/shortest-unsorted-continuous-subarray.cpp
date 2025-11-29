class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        int left = -1, right = nums.size();
        for(int i = 0; i < nums.size(); i++){
            // if(nums[i] >= max_val){
            //     max_val = nums[i];
            // }
            // else right = i;
            (nums[i] >= max_val) ? max_val = nums[i] : right = i;
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] <= min_val) min_val = nums[i];
            else left = i;
        }
        return (left == -1 && right == nums.size()) ? 0 : right - left + 1;
    }
};