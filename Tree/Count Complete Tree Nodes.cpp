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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool flag = false;
        int cnt = 0 ;
        while (!nodes.empty()){
            auto* curr = nodes.front();
            nodes.pop();
            if (!curr->left)
                flag = true;
            if (curr->left && !flag)
                nodes.push(curr->left);
            if (curr->right && !flag)
                nodes.push(curr->right);
            cnt++;
        }
        return cnt;
    }
};