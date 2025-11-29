class Solution {
public:
    int n;
    int mid;

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        n = grid.size();
        mid = grid.size() / 2;
        vector<int> y(3, 0);
        vector<int> ny(3, 0);
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(isY({r, c})) y[grid[r][c]]++;
                else ny[grid[r][c]]++;
            }
        }
        int yMajority = max_element(y.begin(), y.end()) - y.begin();
        int nyMajority = max_element(ny.begin(), ny.end()) - ny.begin();

        int count = 0;
        if (yMajority == nyMajority){
            int secondY = getSecondBest(y, yMajority);
            int secondNy = getSecondBest(ny, nyMajority);
            
            int cost1 = collect(y, secondY) + collect(ny, nyMajority);
            int cost2 = collect(y, yMajority) + collect(ny, secondNy);
            return min(cost1, cost2);
        }

        return collect(y, yMajority) + collect(ny, nyMajority);

    }

    int collect(vector<int>& s, int best){
        if(best == 0) return s[1] + s[2];
        else if(best == 1) return s[0] + s[2];
        else return s[0] + s[1];
    }

    int getSecondBest(vector<int>& s, int best){
        if(best == 0) return (s[1] > s[2]) ? 1 : 2;
        if(best == 1) return (s[0] > s[2]) ? 0 : 2;
        return (s[0] > s[1]) ? 0 : 1;
    }

    bool isY(pair<int, int> pos){
        if(pos.first == pos.second && pos.first >= 0 && pos.first <= mid) return true;
        if(pos.first + pos.second == n - 1 && pos.first >= 0 && pos.first <= mid) return true;
        if(pos.first >= mid && pos.first < n && pos.second == mid) return true;
        return false;
    }
};