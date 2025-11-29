class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> right(n+1, vector<int>());
        for(vector<int>& v : conflictingPairs) right[max(v.front(), v.back())].push_back(min(v.front(), v.back()));
        long long res = 0;
        vector<long long> left = {0, 0};
        vector<long long> bonus(n+1, 0);
        for(int r = 1; r <= n; r++){
            for(int left_bound : right[r]){
                if (left_bound > left[0]) left = {static_cast<long long>(left_bound), left[0]};
                else if (left_bound > left[1]) left = {left[0], static_cast<long long>(left_bound)};
            }
            res += r - left[0];
            if(left[0] > 0) bonus[left[0]] += left[0] - left[1];
        }
        return res + *max_element(bonus.begin(), bonus.end());
    }
};