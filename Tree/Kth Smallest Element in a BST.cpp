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
    int kth(TreeNode* root, int& k) {
        int ans = 0;
        if (root->left)
            ans|=kth(root->left , k);
        if (--k == 0) 
            return root->val;
        if (root->right)
            ans|=kth(root->right , k);
        return ans;
    }
public:
    int kthSmallest(TreeNode* root, int& k) {
        return kth(root , k);
    }
};