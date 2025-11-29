class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int numEven = 0, numOdd = 0;
        for(int n : nums){
            if(n % 2) numOdd++;
            else numEven++;
        }
        int resEven = 0, resOdd = 0;
        for(int n : nums){
            if(n % 2) resOdd = max(resOdd, resEven + 1);
            else resEven = max(resEven, resOdd + 1);
        }
        return max({numEven, numOdd, resEven, resOdd});
    }
};