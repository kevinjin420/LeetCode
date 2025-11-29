class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int n : s){
            if(s.find(n-1) == s.end()){
                int len = 1;
                while(s.find(n+len) != s.end()) len++;
                res = max(res, len);
            }
        }
        return res;
    }
};