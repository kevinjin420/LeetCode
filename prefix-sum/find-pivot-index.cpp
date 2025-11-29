class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        vector<int> left;
        vector<int> right;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            left.push_back(curr += nums[i]);
        }
        curr = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            right.insert(right.begin(), curr += nums[i]);
        }
        if(nums.size() > 1 && right[1] == 0){
            return 0;
        }
        for(int i = 1; i < nums.size() - 1; i++){
            if(left[i-1] == right[i+1]){
                return i;
            }
        }
        if(nums.size() > 1 && left[nums.size() - 2] == 0){
            return nums.size() - 1;
        }
        return -1;
    }
};