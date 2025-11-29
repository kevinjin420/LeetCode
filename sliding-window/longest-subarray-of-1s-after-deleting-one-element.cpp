class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int counter = 0;
        int left = 0;
        int max_len = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                counter++;
            }
            while(counter > 1){
                if(nums[left++] == 0){
                    counter--;
                }
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len - 1;
    }
};