class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> freq;
        int l = 0;
        int res = 0, sum = 0;
        for(int r = 0; r < nums.size(); r++){
            while(freq.find(nums[r]) != freq.end()){
                freq.erase(nums[l]);
                sum -= nums[l];
                l++;
            } 
            freq.insert(nums[r]);
            sum += nums[r];
            res = max(res, sum);
        }
        return res;
    }
};