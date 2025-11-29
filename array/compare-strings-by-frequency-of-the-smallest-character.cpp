class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        unordered_map<int, vector<string>> memo;
        for(string s : words) memo[getFreq(s)].push_back(s);
        vector<int> res;
        for(string q : queries){
            int threshold = getFreq(q);
            int count = 0;
            for(auto entry : memo) if(entry.first > threshold) count += entry.second.size();
            res.push_back(count);
        }
        return res;
    }

    int getFreq(string s){
        char smallest = *min_element(s.begin(), s.end());
        int count = 0;
        for(char c : s) if(c == smallest) count++;
        return count;
    }
};