class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(string& s : strs){
            string original = s;
            sort(s.begin(), s.end());
            m[s].push_back(original);
        }
        vector<vector<string>> res;
        for(auto pair : m) res.push_back(pair.second);
        return res;
    }
};