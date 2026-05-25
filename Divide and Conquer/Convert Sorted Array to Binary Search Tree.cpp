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
    TreeNode* GenerateTree(vector<int>& nums , int l , int r){
        if (l > r)
            return nullptr;
        int mid = l + ((r-l)>>1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->right = GenerateTree(nums , mid + 1 , r);
        root->left = GenerateTree(nums , l , mid - 1);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return GenerateTree( nums , 0 , nums.size() - 1);
    }
};