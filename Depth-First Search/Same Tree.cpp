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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode* , pair<bool , int>>> a , b;
        if (p) a.push({p , {0 , 0}});
        if (q) b.push({q , {0 , 0}});
        while (!a.empty() && !b.empty() && a.front().first->val == b.front().first->val && a.front().second == b.front().second){
            auto front1 = a.front() , front2 = b.front();
            a.pop() , b.pop();
            if (front1.first->left) a.push({front1.first->left , { 0 , front1.second.second + 1}});
            if (front1.first->right) a.push({ front1.first->right ,{ 1 , front1.second.second + 1}});

            if (front2.first->left) b.push({front2.first->left , { 0 , front2.second.second + 1}});
            if (front2.first->right) b.push({front2.first->right,{ 1 , front2.second.second + 1}});
        }
        return  a.empty() && b.empty();
    }
};