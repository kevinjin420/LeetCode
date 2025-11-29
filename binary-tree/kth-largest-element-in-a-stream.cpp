class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    KthLargest(int k_in, vector<int>& nums) :k(k_in) {
        for(int n : nums) add(n);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */