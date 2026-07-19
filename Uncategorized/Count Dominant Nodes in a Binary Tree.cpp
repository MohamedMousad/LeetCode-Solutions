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
    int cnt = 0;
    int rec (TreeNode* root){
        if (!root)
            return 0;
        int mx= max( rec(root->left) ,  rec(root->right));
        if (root->val >= mx)
            cnt++;
        return max(root->val , mx);
    }
public:
    int countDominantNodes(TreeNode* root) {
        rec(root);
        return cnt;
    }
};