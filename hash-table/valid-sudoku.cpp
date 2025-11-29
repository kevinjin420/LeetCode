class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> columns[9];
        unordered_set<int> boxes[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int val=board[i][j]-'0';
                int boxidx=(i/3)*3+(j/3);
                if(!rows[i].insert(val).second) return false;
                if(!columns[j].insert(val).second) return false;
                if(!boxes[boxidx].insert(val).second) return false;
            }
        }
        return true;
    }
};