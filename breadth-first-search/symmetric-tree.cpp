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
    bool isSymmetric(TreeNode* root) {
        return compareSides(root->left, root->right);
    }

    bool compareSides(TreeNode* l, TreeNode* r){
        if(l == nullptr && r == nullptr){
            return true;
        }
        if(l == nullptr || r == nullptr){
            return false;
        }
        if(l->val != r->val){
            return false;
        }
        return compareSides(l->right, r->left) && compareSides(l->left, r->right);
    }

};