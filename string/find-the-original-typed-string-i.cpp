class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        char prev = ' ';
        for(char c : word){
            if(c == prev) count++;
            else prev = c;
        }
        return count;
    }
};