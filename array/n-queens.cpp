class Solution {
public:
    int lim;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        lim = n;
        string temp;
        for(int i = 0; i < n; i++) temp += ".";
        vector<string> board(n, temp);
        unordered_set<int> cols, diags, antidiags;
        backtrack(0, board, cols, diags, antidiags);
        return res;
    }

    void backtrack(int row, vector<string>& board, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidiags){
        if(row == lim){
            res.push_back(board);
            return;
        }
        for(int col = 0; col < lim; col++){
            if(cols.find(col) != cols.end() || diags.find(row - col) != diags.end() || antidiags.find(row + col) != antidiags.end()) continue;
            board[row][col] = 'Q';
            cols.insert(col);
            diags.insert(row - col);
            antidiags.insert(row + col);
            backtrack(row+1, board, cols, diags, antidiags);
            board[row][col] = '.';
            cols.erase(col);
            diags.erase(row - col);
            antidiags.erase(row + col);
        }
    }
};