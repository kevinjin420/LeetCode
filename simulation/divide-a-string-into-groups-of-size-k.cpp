class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res;
        res.reserve((n + k - 1) / k);
        for(int i = 0; i < n;){
            int start = i;
            string curr;
            for(; i < min(start + k, n); i++) curr += s[i];
            res.push_back(curr);
        }
        for(int i = res.back().size(); i < k; i++) res.back() += fill;
        return res;
    }
};