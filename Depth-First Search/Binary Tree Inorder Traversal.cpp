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
    vector<int> values;
    void rec(TreeNode* root){
        if (root == nullptr) return;
        rec(root->left);
        values.push_back(root->val);
        rec(root->right);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return values;
    }
};