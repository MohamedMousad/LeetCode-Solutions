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
    vector<int> ans;
    void dfs(TreeNode* root){
        if (!root) return ;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mn = INT_MAX;
        dfs(root);
        for (int i = 0 ; i <ans.size() - 1 ; i++){
            mn = min (mn , abs(ans[i] - ans[i+1]));
        }
        return mn;
    }
};