class FindSumPairs {
public:
    vector<int> n1;
    vector<int> n2;
    map<int, int> m1;
    map<int, int> m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    : n1(nums1), n2(nums2) {
        for(int n : n1) m1[n]++;
        for(int n : n2) m2[n]++;
    }
    
    void add(int index, int val) {
        m2[n2[index]]--;
        n2[index] += val;
        m2[n2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(auto entry : m1){
            int target = tot - entry.first;
            if(m2.find(target) != m2.end()) count += entry.second * m2[target];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */