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
    void rec(int l , int r , int& i , TreeNode*& curr , vector<int>& inorder , vector<int>& postorder ){
        curr =  new TreeNode(postorder[i]);
        if (i - 1 >= 0 ){
            int idx = find(inorder.begin() , inorder.end() , postorder[i]) - inorder.begin();
            int newIdx = find(inorder.begin() , inorder.end() , postorder[i - 1]) - inorder.begin();
            if (newIdx >= idx + 1 && newIdx <= r)
                rec(idx + 1 , r , --i , curr->right , inorder , postorder);
            if (i -1 >= 0 ){
                newIdx = find(inorder.begin() , inorder.end() , postorder[i-1]) - inorder.begin();
                if (newIdx >= l && newIdx <= idx - 1)
                    rec(l , idx - 1 , --i , curr->left ,  inorder , postorder);
            }
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* tree = nullptr; 
        int i = postorder.size()-1;
        rec(0 , postorder.size() - 1 , i , tree , inorder , postorder);
        return tree;
    }
};