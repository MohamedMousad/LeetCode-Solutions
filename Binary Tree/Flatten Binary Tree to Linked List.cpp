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
    TreeNode* flattenTree(TreeNode*& root){
        if (!root) return root;
        TreeNode* l = nullptr , *r = nullptr; 
        if (!root->left && !root->right)
            return root;
        if (root->left)
            l = flattenTree(root->left);
        if (root->right)
            r = flattenTree(root->right);
        if (l){
            l->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return r ? r : l;
    }
public:
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};