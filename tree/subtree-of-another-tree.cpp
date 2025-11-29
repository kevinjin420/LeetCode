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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == subRoot->val) if(checkSubtrees(curr, subRoot)) return true;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return false;
    }

    bool checkSubtrees(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(a->val != b->val) return false;
        if((a->left && !b->left) || (!a->left && b->left)) return false;
        if((a->right && !b->right) || (!a->right && b->right)) return false;
        return checkSubtrees(a->left, b->left) && checkSubtrees(a->right, b->right);
    }
};