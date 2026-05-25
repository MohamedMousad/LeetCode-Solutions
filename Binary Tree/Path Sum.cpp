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
    bool rec(TreeNode* root, int targetSum) {
        targetSum -= root->val;
        if (!root->right && !root->left)
            return targetSum == 0;
        bool ans = false;
        if (root->right)
            ans|=rec(root->right , targetSum);
        if (root->left)
            ans|=rec(root->left , targetSum);
        return ans;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return rec(root , targetSum);
    }
};