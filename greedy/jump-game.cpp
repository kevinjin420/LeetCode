class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<bool> reach(nums.size(), false);
        reach[0] = true;
        for(int i = 0; i < nums.size(); i++){
            if(reach[i]) for(int j = 0; j < nums[i]; j++){
                if(i+j+1 == nums.size() - 1) return true;
                reach[i+j+1] = true;
            } 
        }
        return false;
    }
};