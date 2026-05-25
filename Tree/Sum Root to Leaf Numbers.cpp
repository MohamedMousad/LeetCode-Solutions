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
    int rec(TreeNode* root , int s = 0){
        if (!root->left && !root->right){
            s+=root->val;
            return s;
        }
        s+=root->val;
        s*=10;
        int sum = 0;
        if (root->left)
            sum+=rec(root->left , s);
        if (root->right)
            sum+=rec(root->right , s);
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return rec(root , 0);
    }
};