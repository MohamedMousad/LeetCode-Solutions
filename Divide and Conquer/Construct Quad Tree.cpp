/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    pair<bool , bool> check_same(int x1, int y1 , int x2 , int y2 , vector<vector<int>>& grid ){
        int bit = grid[x1][y1];
        for (int i = x1 ; i < x2 ; i++){
            for (int j = y1 ; j < y2 ; j++){
                if (grid[i][j] != bit)
                    return {false , bit};
            }
        }
        return {true , bit};
    }
    Node* rec(int x1 , int y1 , int x2 , int y2 , vector<vector<int>>& grid){
        auto check = check_same(x1 , y1 , x2 , y2, grid);
        if (check.first)
            return new Node(check.second, true);
        else{
            int nx = x1 + (x2 - x1)/2 , ny = y1 + (y2 - y1)/2;
            return new Node(check.second , false , 
                    rec(x1, y1 , nx , ny , grid ) ,  
                    rec(x1 , ny , nx , y2 , grid) , 
                    rec(nx , y1 , x2 , ny , grid) , 
                    rec(nx , ny , x2 , y2 , grid));
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return rec(0 , 0 , grid.size() , grid[0].size(), grid);
    }
};