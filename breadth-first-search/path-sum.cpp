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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }

    bool helper(TreeNode* node, int targetSum, int cur){
        if(node == nullptr){
            return false;
        }
        cur += node->val;
        if(node->left == nullptr && node->right == nullptr){
            if(cur == targetSum){
                return true;
            }
            return false;
        }
        return helper(node->left, targetSum, cur) || helper(node->right, targetSum, cur);

    }
};