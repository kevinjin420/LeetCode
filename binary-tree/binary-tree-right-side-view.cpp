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
    vector<int> rightSideView(TreeNode* root) {
        traverse(root, 0);
        return res;
    }

    void traverse(TreeNode* node, int depth){
        if(!node){
            return;
        }
        if(depth == res.size()) {
            res.push_back(node->val); 
        } 
        else{
            res[depth] = node->val;
        }
        traverse(node->left, depth + 1);
        traverse(node->right, depth + 1);
    }

private:
    vector<int> res;
};