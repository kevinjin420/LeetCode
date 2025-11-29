class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int& n : nums) freq[n]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& pair : freq){
            pq.push({pair.second, pair.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};