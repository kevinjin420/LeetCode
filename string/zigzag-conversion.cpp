class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }
        vector<vector<char>> mat(numRows);
        int cur = 0;
        int delta = 1;
        int pos = 0;
        while(pos != s.size()){
            mat[cur].push_back(s[pos]);
            pos++;
            if(cur == 0 && delta == -1){
                delta = 1;
            }
            if(cur == numRows - 1 && delta == 1){
                delta = -1;
            }
            cur += delta;
        }
        string res;
        for(auto v : mat){
            for(auto c : v){
                res += c;
            }
        }
        return res;
    }
};