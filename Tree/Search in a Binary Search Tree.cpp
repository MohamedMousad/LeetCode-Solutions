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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            auto front = nodes.front();
            nodes.pop();
            if (front->left)
                nodes.push(front->left);
            if (front->right)
                nodes.push(front->right);
            if (front->val == val)
                return front;
        }
        return nullptr;
    }
};