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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans(100 , -1000);
        queue<pair<TreeNode*,int>> q;
        q.push({root , 0});
        while (!q.empty()){
            auto front = q.front();
            q.pop();
            if (front.first->left)
                q.push({front.first->left  , front.second + 1 });
            if (front.first->right)
                q.push({front.first->right  , front.second + 1 });
            ans[front.second] = front.first->val;
        }
        while(ans.back() == -1000)
            ans.pop_back();
        return ans;
    }
};