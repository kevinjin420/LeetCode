class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int count = 0;
        for(int n : nums){
            if(curr == n) count++;
            else count--;
            if(count == -1){
                curr = n;
                count = 0;
            } 
        }
        return curr;
    }
};