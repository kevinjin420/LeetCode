class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for(char c : s) m[c]++;
        int maxOdd = 0, minEven = numeric_limits<int>::max();
        for(auto entry : m){
            if(entry.second % 2 == 0){
                minEven = min(minEven, entry.second);
            }
            else{
                maxOdd = max(maxOdd, entry.second);
            }
        }
        return maxOdd - minEven;
    }
};