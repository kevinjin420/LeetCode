class Solution {
public:
    int maxDistance(string s, int k) {
        if(s.size() == k) return k;
        int currX = 0;
        int currY = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'N') currY++;
            else if(s[i] == 'S') currY--;
            else if(s[i] == 'W') currX--;
            else currX++;
            res = max(res, min(abs(currX) + abs(currY) + 2 * k, i + 1));
        }
        return res;
    }
};