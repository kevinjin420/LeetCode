class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i = 0;
        while (i < n) {
            int j = i;
            int lineChars = 0;
            while (j < n && lineChars + words[j].size() + j - i <= maxWidth) {
                lineChars += words[j].size();
                j++;
            }

            int totalSpaces = maxWidth - lineChars;
            int numGaps = j - i - 1;

            string line;

            if (j == n || numGaps == 0) {
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k != j-1) line += " ";
                }
                while(line.size() < maxWidth) line += " ";
            }
            else {
                int spaceSize = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = spaceSize + (extraSpaces > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};