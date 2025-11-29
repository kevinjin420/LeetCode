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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        collect(root, "");
        return res;
    }

    void collect(TreeNode* node, string s){
        s += "->";
        s += to_string(node->val);
        if(!node->left && !node->right){
            s.erase(0, 2);
            res.push_back(s);
            return;
        }
        if(node->left) collect(node->left, s);
        if(node->right) collect(node->right, s);
    }

    vector<string> res;
};