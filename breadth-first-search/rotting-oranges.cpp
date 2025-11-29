class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int uninfected = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                } 
                else if(grid[i][j] == 1) uninfected++;
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if(q.empty() && !uninfected) return 0;

        int res = 0;
        while(q.size()){
            int curSize = q.size();
            for(int i = 0; i < curSize; i++){
                pair<int, int> curr = q.front(); q.pop();
                for(pair<int, int> p : directions){
                    pair<int, int> newPos = {curr.first + p.first, curr.second + p.second};
                    if(newPos.first >= 0 && newPos.first < m && newPos.second >= 0 && newPos.second < n 
                        && !visited[newPos.first][newPos.second] &&grid[newPos.first][newPos.second] == 1){
                        uninfected--;
                        grid[newPos.first][newPos.second] = 2;
                        visited[newPos.first][newPos.second] = true;
                        q.push(newPos);
                    }
                }
            }
            res++;
        }

        if(uninfected) return -1;
        return res - 1;
    }
};