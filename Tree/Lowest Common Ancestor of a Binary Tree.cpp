/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int , int> mp;
    bool dfs(TreeNode* root ,int target){
        if (root->val == target)
            return true;
        if (root->left && dfs(root->left , target)){
            mp[root->left->val] += 1;
            return true;
        }
        if (root->right && dfs(root->right , target)){
            mp[root->right->val] += 1;
            return true;
        }
        else return false;
    }
    TreeNode* find(TreeNode* root){
        if (root->left && mp[root->left->val] == 2)
            return find(root->left);
        else if (root->right && mp[root->right->val] == 2)
            return find(root->right);
        else
            return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root , p->val);
        dfs(root , q->val);
        return find(root);
    }
};