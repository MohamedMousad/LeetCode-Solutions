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
    vector<int> a, b;
    void dfs (TreeNode* root){
        if (!root->left && !root->right )
            a.push_back(root->val);
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
    }
    void dfs2 (TreeNode* root){
        if (!root->left && !root->right )
            b.push_back(root->val);
        if (root->left)
            dfs2(root->left);
        if (root->right)
            dfs2(root->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs2(root2);
        return a == b;
    }
};