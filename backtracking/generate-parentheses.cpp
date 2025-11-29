class Solution {
public:
    vector<string> generateParenthesis(int n){
        vector<string> res;
        helper(n, res, "", 0, 0);
        return res;
    }

    void helper(int n, vector<string> &res, string cur, int left, int right){
        if(left == n && right == n){
            res.push_back(cur);
            return;
        }

        if(left < n){
            helper(n, res, cur + "(", left + 1, right);
        }
        if(right < left){
            helper(n, res, cur + ")", left, right + 1);
        }
    }
};