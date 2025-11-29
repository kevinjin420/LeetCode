class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::set set1(nums1.begin(), nums1.end());
        std::set set2(nums2.begin(), nums2.end());
        vector<int> res1;
        vector<int> res2;
        for(int s1 : nums1){
            if(!set2.contains(s1) && find(res1.begin(), res1.end(), s1) == res1.end()){
                res1.push_back(s1);
            }
        }
        for(int s2 : nums2){
            if(!set1.contains(s2) && find(res2.begin(), res2.end(), s2) == res2.end()){
                res2.push_back(s2);
            }
        }
        return {res1, res2};
    }
};