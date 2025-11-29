class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtree_xor;
    vector<std::unordered_set<int>> descendants;

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        adj.assign(n, vector<int>());
        subtree_xor.assign(n, 0);
        descendants.assign(n, unordered_set<int>());

        for(vector<int>& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);

        int total_xor = subtree_xor.front();
        int res = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int xor_i = subtree_xor[i];
                int xor_j = subtree_xor[j];
                int val1, val2, val3;
                if (descendants[i].count(j)) {
                    val1 = xor_j;
                    val2 = xor_i ^ xor_j;
                    val3 = total_xor ^ xor_i;
                } 
                else if (descendants[j].count(i)) {
                    val1 = xor_i;
                    val2 = xor_j ^ xor_i;
                    val3 = total_xor ^ xor_j;
                } 
                else {
                    val1 = xor_i;
                    val2 = xor_j;
                    val3 = total_xor ^ xor_i ^ xor_j;
                }
                int score = max({val1, val2, val3}) - min({val1, val2, val3});
                res = min(res, score);
            }
        }

        return res;
    }

    void dfs(int node, int parent, vector<int>& nums){
        subtree_xor[node] = nums[node];
        descendants[node].insert(node);

        for(int child : adj[node]){
            if(child == parent) continue;
            dfs(child, node, nums);
            subtree_xor[node] ^= subtree_xor[child];
            descendants[node].insert(descendants[child].begin(), descendants[child].end());
        }
    }
};