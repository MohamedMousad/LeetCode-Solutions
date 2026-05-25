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
    long long t {};
    long long count {};
    void sum(TreeNode* root){
        t+=root->val;
        if (!root->right && !root->left){
            count+=t;
            return ;
        }
        if (root->left){
            t<<=1;
            sum(root->left);
            t>>=1;
        }
        if (root->right){
            t<<=1;
            sum(root->right);
            t>>=1;
        }
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum(root);
        return count;
    }
};