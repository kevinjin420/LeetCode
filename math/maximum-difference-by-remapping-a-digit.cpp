class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char maxToReplace = ' ';
        char minToReplace = ' ';
        for(char c : s){
            if(c != '9' && maxToReplace == ' ') maxToReplace = c;
            if(c != '0' && minToReplace == ' ') minToReplace = c;
            if(maxToReplace != ' ' && minToReplace != ' ') break;
        }
        string maxRes;
        string minRes;
        for(char c : s){
            if(c == maxToReplace) maxRes += '9';
            else maxRes += c;

            if(c == minToReplace) minRes += '0';
            else minRes += c;
        }
        return stoi(maxRes) - stoi(minRes);
    }
};