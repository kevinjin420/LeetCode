class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        vector<int> res;
        vector<pair<int, int>> last(v.end() - k, v.end());
        sort(last.begin(), last.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });
        for (const auto &p : last) res.push_back(p.first);
        return res;
    }
};