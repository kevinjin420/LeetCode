/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getSwap(vector<int>& level){
        int count = 0;
        vector<int> sorted = level;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> m;
        for(int i = 0; i < level.size(); i++){
            m[level[i]] = i;
        }
        for(int i = 0; i < level.size(); i++){
            if(level[i] != sorted[i]){
                count++;
                int curPos = m[sorted[i]];
                m[level[i]] = curPos;
                swap(level[i], level[curPos]);
            }
        }
        return count;
    }

    int minimumOperations(TreeNode* root) {
        int count = 0;
        queue<TreeNode*> level;
        level.push(root);
        while(level.size()){
            int level_size = level.size();
            vector<int> curr;
            for(int i = 0; i < level_size; i++){
                curr.push_back(level.front()->val);
                if(level.front()->left) level.push(level.front()->left);
                if(level.front()->right) level.push(level.front()->right);
                level.pop();
            }
            count += getSwap(curr);
        }
        return count;
    }
};