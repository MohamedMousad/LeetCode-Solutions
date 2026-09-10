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
    int res = 0;
    pair<int,int> rec(TreeNode* root){
        int cnt = 1 , sum = root->val , avr = 0 , sum2 = 0 , cnt2;
        if (root->left){
            auto [sum1 , cnt1] = rec(root->left);
            sum+=sum1 , cnt+=cnt1;
        }
        if (root->right){
            auto [sum1 , cnt1] = rec(root->right);
            sum+=sum1 , cnt+=cnt1;
        }
        res+=((sum/cnt) == root->val);
        return {sum , cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        rec(root);
        return res;
    }
};