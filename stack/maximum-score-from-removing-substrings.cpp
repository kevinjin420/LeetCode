class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string high, low;
        int high_pts = max(x, y), low_pts = min(x,y);
        if(x > y){ high = "ab"; low = "ba"; }
        else{ high = "ba"; low = "ab"; }

        string stack;
        for(char c : s){
            if(!stack.empty() && stack.back() == high[0] && c == high[1]){
                res += high_pts;
                stack.pop_back();
            }
            else stack.push_back(c);
        }
        string s2 = stack;
        stack = "";
        for(char c : s2){
            if(!stack.empty() && stack.back() == low[0] && c == low[1]){
                res += low_pts;
                stack.pop_back();
            }
            else stack.push_back(c);
        }
        return res;
    }
};