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
    TreeNode* recoverFromPreorder(string traversal){
        if(traversal == "") return nullptr;
        int depth = 0;
        int pos = 0;
        TreeNode* root = new TreeNode(getNum(pos, traversal));
        buildChildren(root, ++pos, depth+1, traversal);
        buildChildren(root, ++pos, depth+1, traversal);
        return root;
    }

    void buildChildren(TreeNode* node, int& pos, int depth, string traversal){
        if(pos >= traversal.size()) return;
        cout << "start pos " << pos << " depth " << depth << " node val: " << node->val << "\n";
        int count = 0;
        while(pos < traversal.size() && traversal[pos] == '-'){ pos++; count++;}
        if(pos == traversal.size()) return;
        if(count != depth){pos -= (count + 1); return;}
        if(!node->left){
            node->left = new TreeNode(getNum(pos, traversal));
            buildChildren(node->left, ++pos, depth+1, traversal);
            buildChildren(node->left, ++pos, depth+1, traversal);
        }
        else{
            node->right = new TreeNode(getNum(pos, traversal));
            buildChildren(node->right, ++pos, depth+1, traversal);
            buildChildren(node->right, ++pos, depth+1, traversal);
        }
    }

    int getNum(int& pos, string traversal){
        int res = traversal[pos] - '0';
        while(++pos < traversal.size() && traversal[pos] != '-') res = res * 10 + traversal[pos] - '0';
        pos--;
        return res;
    }
};