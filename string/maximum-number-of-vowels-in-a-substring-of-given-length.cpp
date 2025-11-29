class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = k;
        int curVowels = 0;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < k; i++){
            if(std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()){
                curVowels++;
            }
        }
        int maxVowels = curVowels;
        for(int i = 0; i < s.size() - k; i++){
            if(std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()){
                curVowels--;
            }
            if(std::find(vowels.begin(), vowels.end(), s[i+k]) != vowels.end()){
                curVowels++;
            }
            maxVowels = max(maxVowels, curVowels);
        }
        return maxVowels;
        
    }
};