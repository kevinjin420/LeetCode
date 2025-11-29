class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> m(26);
        priority_queue<char, vector<char>, std::greater<char>> pq;
        vector<bool> avoid(s.size(), false);
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){
                m[s[i] - 'a'].push(i);
                pq.push(s[i]);
            }
            else{
                avoid[i] = true;
                avoid[m[pq.top() - 'a'].top()] = true;
                m[pq.top() - 'a'].pop();
                pq.pop();
            }
        }
        string res;
        for(int i = 0; i < s.size(); i++) if(!avoid[i]) res += s[i];
        return res;
    }
};