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
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }

    int helper(TreeNode* node, int maxSoFar){
        if(node == nullptr){
            return 0;
        }
        if(node->val < maxSoFar){
            return helper(node->left, maxSoFar) + helper(node->right, maxSoFar);
        }
        return 1 + helper(node->left, node->val) + helper(node->right, node->val);
    }
};