class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        bool hasZero = false;
        int max_neg = INT_MIN;
        unordered_set<int> seen;
        for(int n : nums){
            if(n > 0 && seen.find(n) == seen.end()){ sum += n; seen.insert(n); }
            else if(n < 0) max_neg = max(max_neg, n);
            else hasZero = true;
        }
        if(!seen.size()){
            if(hasZero) return 0;
            return max_neg;
        }
        return sum;
    }
};