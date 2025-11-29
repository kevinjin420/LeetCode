class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        stack<char> st;
        string res;
        for(char c : s) freq[c - 'a']++;
        for(char c : s){
            st.push(c);
            freq[c - 'a']--;
            while(st.size() && st.top() <= getMin(freq)){
                res += st.top();
                st.pop();
            } 
        }
        while(st.size()){
            res += st.top();
            st.pop();
        }
        return res;
    }

    char getMin(vector<int>& freq){
        for(int i = 0; i < freq.size(); i++) if(freq[i]) return ('a' + i);
        return 'a';
    }
};