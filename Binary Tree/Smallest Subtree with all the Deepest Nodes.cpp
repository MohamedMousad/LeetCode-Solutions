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
    int dp[505]  = {};
    TreeNode* ans = nullptr;
    int maxDepth(TreeNode* node){
        if (!node) return 0;
        if (~dp[node->val]) return dp[node->val];
        return dp[node->val] = max(maxDepth(node->left) , maxDepth(node->right)) + 1;        
    }
    TreeNode* find_subtree(TreeNode* node){
        if (maxDepth(node->left) == maxDepth(node->right))
            return node;
        else if (maxDepth(node->left) > maxDepth(node->right))
            return find_subtree(node->left);
        else 
            return find_subtree(node->right);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        memset(dp , -1 , sizeof dp);
        maxDepth(root);
        return find_subtree(root);
    }
};