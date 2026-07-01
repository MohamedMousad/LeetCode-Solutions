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
    // Tree rec(TreeNode* root, int val){
    //     if (!root)
    //         return new TreeNode(val);
    //     if (val > root->val)
    //         root->right = rec(root->right , val);
    //     else if (val < root->val)
    //         root->left = rec(root->left , val);
    //     return root;
    // }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (val > root->val)
            root->right = insertIntoBST(root->right , val);
        else if (val < root->val)
            root->left = insertIntoBST(root->left , val);
        return root;
    }
};