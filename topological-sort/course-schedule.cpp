class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> taken;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int> v : prerequisites) m[v[0]].push_back(v[1]);
        for(int i = 0; i < numCourses; i++) if(!dfs(i)) return false;
        return true;
    }

    bool dfs(int c){
        if(m[c].empty()) return true;
        if(taken.find(c) != taken.end()) return false;
        taken.insert(c);
        for(int n : m[c]) if(!dfs(n)) return false;
        m[c].clear();
        return true;
    }
};