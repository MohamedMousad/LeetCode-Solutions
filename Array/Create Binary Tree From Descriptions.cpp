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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        unordered_map<int , bool> nodes;
        for (int i = 0 ; i < descriptions.size() ; i++){
            if (mp.count(descriptions[i][0]) == 0)
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]) , nodes[descriptions[i][0]] = false;
            if (mp.count(descriptions[i][1]) == 0)
                mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]) ;
            if (descriptions[i][2])
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            else 
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            nodes[descriptions[i][1]] = true;
        }
        for (auto& node : nodes)
            if (!node.second)
                return mp[node.first];
        return nullptr;
    }
};