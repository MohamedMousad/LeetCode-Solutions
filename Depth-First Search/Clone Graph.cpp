/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* mp[105] = {};
    Node* dfs(Node* node){
        if (node){
            Node* new_node = new Node(node->val);
            mp[node->val] = new_node;
            for (int i = 0 ;i < node->neighbors.size() ; i++){
                if (!mp[node->neighbors[i]->val])
                    new_node->neighbors.push_back(dfs(node->neighbors[i]));
                else 
                    new_node->neighbors.push_back(mp[node->neighbors[i]->val]);
            }
            return new_node;
        }
        return nullptr;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};