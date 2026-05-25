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
    long long get_max(TreeNode*& root , long long& count){
        if (!root)
            return 0;
        return max((long long)root->val*(count - root->val) ,
                    max( get_max(root->left , count) , get_max(root->right ,count))
                );
    }
    long long sum(TreeNode*& root){
        if (!root)
            return 0;
        return root->val = root->val + sum(root->left) + sum(root->right);
    }
public:
    int maxProduct(TreeNode* root) {
        const int mod = 1e9 + 7;
        long long count = sum(root);
        return get_max(root , count)%mod;
    }
};