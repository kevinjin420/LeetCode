class Solution {
public:
    struct pos {
        int row;
        int col;

        pos operator+(const pos& other) const {
            return { row + other.row, col + other.col };
        }
    };

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<pos> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int curSum = 0;
                    queue<pos> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        pos curr = q.front();
                        q.pop();
                        curSum++;
                        for(pos dir : directions) {
                            pos newPos = curr + dir;
                            if(isValid(newPos, grid.size(), grid[0].size()) && 
                               !visited[newPos.row][newPos.col] && 
                               grid[newPos.row][newPos.col]) {
                                visited[newPos.row][newPos.col] = true;
                                q.push(newPos);
                            }
                        }
                    }
                    res = max(res, curSum);
                }
            }
        }
        return res;
    }

    bool isValid(pos newPos, int r, int c) {
        return newPos.row >= 0 && newPos.row < r && newPos.col >= 0 && newPos.col < c;
    }
};
