class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window;
        int max_len = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while(window.contains(s[i]) && left < i){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            max_len = max(max_len, i-left+1);
        }
        return max_len;
    }
};