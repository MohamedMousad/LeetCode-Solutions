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
    bool is_mirror(TreeNode* first ,TreeNode* second){
        if (first == nullptr && second == nullptr)
            return true;
        if ((first && !second) || (!first && second) || (first && second && first->val != second->val))
            return false;
        else 
            return is_mirror(first->right , second->left) && is_mirror(first->left , second->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root->right , root->left);
    }
};