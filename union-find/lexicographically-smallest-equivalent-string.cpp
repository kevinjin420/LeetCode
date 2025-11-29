class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unionFind(int x, int y, vector<int>& parent){
        int parentX = find(x, parent);
        int parentY = find(y, parent);
        if(parentX < parentY) parent[parentY] = parentX;
        else if(parentX > parentY) parent[parentX] = parentY;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> chars(26, 0); // 0 = 'a', 25 = 'z'
        for(int i = 0; i < 26; i++) chars[i] = i;
        for(int i = 0; i < s1.size(); i++){
            int low = min(s1[i], s2[i]) - 'a';
            int high = max(s1[i], s2[i]) - 'a';
            unionFind(low, high, chars);
        }
        string res;
        for(char c : baseStr) res += ('a' + find(c - 'a', chars));
        return res;
    }
};