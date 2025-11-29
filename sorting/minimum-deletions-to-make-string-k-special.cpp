class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for(char c : word) freq[c]++;
        int res = numeric_limits<int>::max();
        for(auto i : freq){
            int toDel = 0;
            for(auto j : freq){
                if(j.second < i.second) toDel += j.second;
                else if(j.second > i.second + k) toDel += j.second - i.second - k;
            }
            res = min(res, toDel);
        }
        return res;

    }
};