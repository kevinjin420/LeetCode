class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int n : nums1) set1.insert(n);
        for(int n : nums2) set2.insert(n);
        vector<int> res;
        for(int entry : set1) if(set2.find(entry) != set2.end()) res.push_back(entry);
        return res;
    }
};