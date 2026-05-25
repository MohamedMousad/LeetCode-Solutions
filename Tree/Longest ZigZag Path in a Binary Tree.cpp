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
    int ans = 0;
    void rec(TreeNode* node , int state , int sum){
        if (node->right && state != 1)
            ans = max(ans , sum+1 ) , rec(node->right , 1 , sum + 1 );
        else if (node->right && state == 1)
            ans = max(ans , 1 ) , rec(node->right , 1 , 1);
        if (node->left && state != 0)
            ans = max(ans , sum+1 ) , rec(node->left , 0, sum + 1 );
        else if ( node->left && state == 0)
            ans = max(ans , 1 ) , rec(node->left , 0 , 1);
        return;
    }
public:
    int longestZigZag(TreeNode* root) {
        rec(root , -1 , 0);
        return ans;
    }
};