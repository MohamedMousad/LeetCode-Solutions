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
    int rec(TreeNode* root , bool ok ){
        if (!root)
            return 0;
        int sum = 0;
        if (ok && !root->left && !root->right)
            sum+=root->val;
        return sum + rec(root->left , 1) + rec(root->right , 0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return rec(root , 0);
    }
};