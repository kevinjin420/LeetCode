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
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        if(abs(helper(root->left, 0) - helper(root->right, 0)) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
        
    }

    int helper(TreeNode* node, int depth){
        if(node == nullptr){
            return depth;
        }
        return max(helper(node->left, depth + 1), helper(node->right, depth + 1));
    }
};