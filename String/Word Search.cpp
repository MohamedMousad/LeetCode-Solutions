class Solution {
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = { 0 , 0 , -1 , 1};
    bool rec(int i, int j , int o , vector<vector<char>>& board, string& word){
        if (board[i][j] != word[o]){
            return false;
        }
        if (o == word.size() - 1)
            return true;
        board[i][j] = '#';
        for (int k = 0 ; k  < 4 ; k++){
            int nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[i].size() && board[nx][ny]!='#'){
                if (rec(nx , ny , o+1 , board , word))
                    return true;
            }
        }
        board[i][j] = word[o];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i< board.size() ; i++){
            for (int j = 0 ; j < board[i].size() ; j++){
                if (rec(i , j , 0 , board ,word))
                    return true;
            }
        }
        return false;
    }
};