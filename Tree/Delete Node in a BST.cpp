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
    pair<TreeNode*, TreeNode*> get_least(TreeNode* root ){
        auto curr = root ; TreeNode* par = nullptr;
        while(curr->left)
            par = curr , curr = curr->left;
        return make_pair(curr , par);
    }
    pair<TreeNode* , TreeNode*> find(TreeNode* root , int key , TreeNode* par = nullptr){
        if (!root) return {nullptr , par};
        if (root->val < key )
            return find(root->right , key , root);
        else if (root->val > key )
            return find(root->left , key , root);
        else
            return { root , par};
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto curr = find(root , key);
        auto par = curr.second;
        auto child = curr.first;
        if (!child) return root;
        if (!child->right && !child->left){
            if (par == nullptr) {
                delete child;
                return nullptr;
            }
            
            if (par->left == child) par->left = nullptr;
            else par->right = nullptr;
            delete child;
            return root; 
        }
        if (!child->right){
            if (par == nullptr){
                auto newRoot = child->left; 
                delete child;
                return newRoot;
            }
            if (par->left == child) par->left = child->left;
            else par->right = child->left;
            
            delete child;
        }
        else{
            int temp = child->val;
            auto least = get_least(child->right);
            auto leastChild = least.first;
            auto leastPar =  least.second;
            // swap
            child->val = leastChild->val;
            leastChild->val = temp;
            child->right = deleteNode(child->right ,temp);
        }
        return root;
    }
};