class Solution {
    // right , down , left , up ->repeat
    int dx[4] = { 0 ,  1 , 0 ,  -1 };
    int dy[4] = { 1 ,  0 , -1 ,  0 };
    vector<int> res;
    void rec(vector<vector<bool>>& vis , vector<vector<int>>& matrix , int i , int j,int op ){
        if ( i < 0 ||i >= matrix.size() || j >= matrix[0].size() || j < 0 || vis[i][j])
            return;
        res.push_back(matrix[i][j]);
        vis[i][j] = true;
        int nx = i + dx[op] , ny = j + dy[op];
        if ( nx < 0 || nx >= matrix.size() || ny >= matrix[0].size() || ny < 0 || vis[nx][ny])
            op = (op+1)%4 , nx = i + dx[op] , ny = j + dy[op];
        rec(vis , matrix , nx, ny , op);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> vis(matrix.size() , vector<bool>(matrix[0].size()));
        rec(vis , matrix , 0 , 0 , 0);
        return res;
    }
};