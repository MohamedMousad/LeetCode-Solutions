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
    int balanced(TreeNode* root){
        if (!root)
            return 0;
        int left = balanced(root->left);
        int right = balanced(root->right);
        if (left == -11 || right == -11)
            return -11;
        if (abs(left - right) <= 1 )
            return 1 + max(left , right);
        else
            return -11;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanced(root) != -11;
    }
};