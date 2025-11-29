class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string res = "";
        queue<string> q;
        q.push("");
        while(q.size()){
            string curr = q.front(); q.pop();
            for(char c = 'a'; c <= 'z'; c++){
                string next = curr + c;
                if(hasK(next, s, k)){
                    res = next;
                    q.push(next);
                }
            }
        }
        return res;
    }

    bool hasK(string substr, string s, int k){
        int count = 0, i = 0;
        for(char c : s) if(c == substr[i] && ++i == substr.size()){
            i = 0;
            if(++count == k) return true;
        }
        return false;
    }
};