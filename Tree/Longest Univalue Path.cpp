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
    int ans = 1;
    pair<int,bool> rec(TreeNode* root , int val){
        if (!root)
            return {0 , 0};
        auto l = rec(root->left , root->val) , r = rec(root->right , root->val);
        int curr = 0;
        ans = max(ans , l.first);
        ans = max(ans , r.first);
        if (l.second && r.second){
            curr = l.first + r.first + 1;
            ans = max(ans  ,curr);
        }
        else if (l.second){
            curr = l.first + 1;
            ans = max(ans , curr);
        }
        else if (r.second){
            curr = r.first + 1;
            ans = max(ans , curr);
        }
        if (root->val == val){
            int sum = 0;
            if (l.second)
                sum = max(sum , l.first);
            if (r.second)
                sum = max(sum , r.first);
            return { sum + 1 , 1};
        }
        return {curr , 0};
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        rec(root , -2000);
        return ans - 1;
    }
};