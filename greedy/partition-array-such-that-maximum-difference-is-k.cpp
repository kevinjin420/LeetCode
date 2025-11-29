class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        int currMin = nums.front();
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - currMin > k){
                count++;
                currMin = nums[i];
            }
            else currMin = min(currMin, nums[i]);
        }
        return count + 1;
    }
};