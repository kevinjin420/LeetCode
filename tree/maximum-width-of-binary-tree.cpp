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
    int widthOfBinaryTree(TreeNode* root) {
        long long res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()){
            long long first = 0;
            long long last = 0;
            long long size = q.size();
            for(long long i = 0; i < size; i++){
                TreeNode* curr = q.front().first;
                long long index = q.front().second;
                q.pop();
                if(i == 0) first = index;
                if(i == size - 1) last = index;
                if(curr->left) q.push({curr->left, index * 2 + 1});
                if(curr->right) q.push({curr->right, index * 2 + 2});
            }
            res = max(res, last - first + 1);
        }
        return res;
    }
};