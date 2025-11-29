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
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, LONG_MIN, LONG_MAX);
    }

    bool isValidNode(TreeNode* node, long lower, long upper){
        if(!node) return true;

        if(node->left && (node->left->val <= lower || node->left->val >= node->val)) return false;
        if(node->right && (node->right->val >= upper || node->right->val <= node->val)) return false;

        return isValidNode(node->left, lower, node->val) && isValidNode(node->right, node->val, upper);
    }
};