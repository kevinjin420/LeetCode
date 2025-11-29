class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        vector<int> copy = {nums.front()};
        for(int i = 1; i < nums.size(); i++) if(nums[i] != copy.back()) copy.push_back(nums[i]);
        for(int i = 1; i < copy.size() -1; i++) if((copy[i] > copy[i-1] && copy[i] > copy[i+1]) || (copy[i] < copy[i-1] && copy[i] < copy[i+1])) count++;
        return count;
    }
};