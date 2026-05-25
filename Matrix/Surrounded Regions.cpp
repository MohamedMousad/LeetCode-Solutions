class Solution {
    int dx [4] ={0 , 0 , -1 , 1};
    int dy [4]  = {1 , -1, 0 , 0 };
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis , int i  , int j){
        if (((i == 0) ||( j == 0) || (j == board[0].size() - 1) || (i == board.size() - 1)) && board[i][j] == 'O')
            return true;
        vis[i][j]++;
        bool ch = false;
        for (int k = 0 ; k < 4 ; k++){
            int nx = i + dx[k] , ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && vis[nx][ny] == 0 && board[nx][ny] == 'O')
                ch|=dfs(board , vis , nx, ny);
        }
        return ch;
    }
    void fill(vector<vector<char>>& board, vector<vector<int>>& vis , int i  , int j){
        board[i][j] = 'X' , vis[i][j]++;
        for (int k = 0 ; k < 4 ; k++){
            int nx = i + dx[k] , ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && vis[nx][ny] < 2 && board[nx][ny] == 'O')
                fill(board , vis , nx, ny);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size() , vector<int>(board[0].size() , false));
        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++){
                if (vis[i][j] == 0 && board[i][j] == 'O' && !dfs(board , vis , i , j)) 
                    fill(board , vis , i , j);
            }
        }
    }
};