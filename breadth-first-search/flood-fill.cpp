class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int target = image[sr][sc];
        queue<vector<int>> q;
        q.push({sr, sc});
        while(q.size()){
            vector<int> curr = q.front();
            q.pop();
            image[curr[0]][curr[1]] = color;
            visited[curr[0]][curr[1]] = true;
            for(vector<int> dir : directions){
                vector<int> new_loc;
                new_loc.push_back(curr[0] + dir[0]);
                new_loc.push_back(curr[1] + dir[1]);
                if(isValid(new_loc, image.size(), image[0].size()) && !visited[new_loc[0]][new_loc[1]] && image[new_loc[0]][new_loc[1]] == target){
                    q.push(new_loc);
                }
            }
        }
        return image;
    }

    bool isValid(vector<int> pos, int r, int c){
        return pos[0] >= 0 && pos[0] < r && pos[1] >= 0 && pos[1] < c;
    }
};