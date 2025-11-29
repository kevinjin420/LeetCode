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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int>& nums, int begin, int end){
        if(begin >= end){
            return nullptr;
        }
        int mid = begin + (end - begin) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, begin, mid);
        node->right = helper(nums, mid+1, end);
        return node;
    }
};