class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> set1;
        unordered_map<int, int> set2;
        for(int n : nums1) set1[n]++;
        for(int n : nums2) set2[n]++;
        vector<int> res;
        for(auto entry : set1){
            for(int i = 0; i < min(entry.second, set2[entry.first]); i++) res.push_back(entry.first);
        }
        return res;
    }
};