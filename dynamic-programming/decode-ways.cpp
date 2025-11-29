class Solution {
public:
    unordered_map<string, int> memo;
    int numDecodings(string input) {
        if(input.empty()) return 1;
        if(input[0] == '0') return 0;
        if(input.size() == 1) return 1;
        if(memo.find(input) != memo.end()) return memo[input];

        int ways = numDecodings(input.substr(1));
        if(stoi(input.substr(0, 2)) <= 26) ways += numDecodings(input.substr(2));
        memo[input] = ways;
        return ways;
    }
};