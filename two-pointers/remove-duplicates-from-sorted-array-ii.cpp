class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::pair<int, int> cur = {INT_MIN,0};
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != cur.first){
                cur.first = nums[i];
                cur.second = 1;
            }
            else if(nums[i] == cur.first && cur.second >= 2){
                nums.erase(nums.begin() + i);
                i--;
            }
            else{
                cur.second++;
            }
            i++;
        }
        return i;
    }

};