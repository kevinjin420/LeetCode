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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preQ(preorder.begin(), preorder.end());
        return build(preQ, inorder);
    }

    TreeNode* build(deque<int>& preorder, vector<int>& inorder){
        if(inorder.empty()) return nullptr;
        int top = preorder.front();
        preorder.pop_front();
        int index = find(inorder.begin(), inorder.end(), top) - inorder.begin();
        TreeNode* node = new TreeNode(top);
        vector<int> left(inorder.begin(), inorder.begin() + index);
        vector<int> right(inorder.begin() + index + 1, inorder.end());
        node->left = build(preorder, left);
        node->right = build(preorder, right);
        return node;
    }
};