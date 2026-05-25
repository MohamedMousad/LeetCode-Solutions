class Solution {
    int dx[8] = { 0 , 0,  1 , 1 , 1 , -1 , -1 , -1 };
    int dy[8] = { 1 , -1 ,  1 , -1 , 0 , -1 , 1 , 0 };
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<bool>> state(board.size() , vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0 ; j < board[0].size() ; j++){
                int cnt = 0;
                for (int k  = 0 ; k < 8 ; k++){
                    int nx = i + dx[k] , ny = j + dy[k];
                    if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] )
                        cnt++;
                }
                if (board[i][j] && (cnt == 2 || cnt == 3) || (board[i][j] == 0 && cnt == 3))
                    state[i][j] = true;
            }
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0 ; j < board[0].size() ; j++){
                board[i][j] = state[i][j];
            }
        }       
    }
};