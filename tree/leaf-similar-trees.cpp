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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        collect(root1, v1);
        collect(root2, v2);
        if(v1.size() != v2.size()){
            return false;
        }
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }

    void collect(TreeNode* root, vector<int> &vec){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            vec.push_back(root->val);
            return;
        }
        collect(root->left, vec);
        collect(root->right, vec);
    }
};