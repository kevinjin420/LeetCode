class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0, res = 0;
        while(right < s.size()){
            res = max(res, ++freq[s[right] - 'A']);
            if(right - left + 1 - res > k) --freq[s[left++] - 'A'];
            right++;
        }
        return s.size() - left;
    }
};