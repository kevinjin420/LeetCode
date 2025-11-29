/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        traverse(root, 0);
        int max_val = *max_element(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            if(res[i] == max_val){
                return i + 1;
            }
        }
        return -1;
    }

    void traverse(TreeNode* node, int depth){
        if(!node){
            return;
        }
        if(res.size() == depth){
            res.push_back(node->val);
        }
        else{
            res[depth] += node->val;
        }
        traverse(node->left, depth + 1);
        traverse(node->right, depth + 1);
    }
private:
    vector<int> res;
};