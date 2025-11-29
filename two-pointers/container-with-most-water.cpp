class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_ans = 0;
        while(left < right){
            max_ans = max(max_ans, min(height[left], height[right]) * (right - left));
            if(height[right] > height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_ans;
        
    }
};