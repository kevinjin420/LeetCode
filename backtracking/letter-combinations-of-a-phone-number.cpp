class Solution {
public:
    vector<vector<char>> dict;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        dict = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        string s;
        backtrack(digits, s, 0);
        return res;
    }

    void backtrack(string& s, string& curr, int index){
        if(index == s.size()){
            res.push_back(curr);
            return;
        }
        for(char c : dict[s[index] - '2']){
            curr += c;
            backtrack(s, curr, index + 1);
            curr.pop_back();
        }
    }
};