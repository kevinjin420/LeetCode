class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        std::set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        std::set<char> nums({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
        bool hasVowel = false;
        bool hasConsonant = false;
        for(char c : word){
            if((c < '0' || c > '9') && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) return false;
            if(vowels.find(c) != vowels.end()) hasVowel = true;
            else if(nums.find(c) == nums.end()) hasConsonant = true;
        }
        return hasVowel && hasConsonant;
    }
};