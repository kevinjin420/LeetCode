class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        stringstream ss(path);
        string word;

        while (getline(ss, word, '/')) {
            if (word.empty() || word == ".") continue;
            if (word == ".."){
                if(!dq.empty()) dq.pop_back();
                continue;
            }
            dq.push_back(word);
        }

        string res;
        while (!dq.empty()) {
            res += "/";
            res += dq.front();
            dq.pop_front();
        }
        if (res.empty()) res = "/";
        return res;

    }
};