class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0 ; i < board.size() ; i++){
            int freq [10] = {};
            for (int j = 0 ; j < board.size(); j++){
                if (board[i][j] == '.') continue;
                if (freq[board[i][j] - '0'] >= 1) return false;
                freq[board[i][j] - '0']++;
            }
        }
        for (int j = 0 ; j < board.size() ; j++){
            int freq [10] = {};
            for (int i = 0 ; i < board.size(); i++){
                if (board[i][j] == '.') continue;
                if (freq[board[i][j] - '0'] >= 1) return false;
                freq[board[i][j] - '0']++;
            }
        }
        for (int row = 0 ; row < 3 ; row++){
            for (int col = 0 ; col < 3 ; col++){
                int freq [10] = {};
                for (int i = row*3 ; i < min((int) board.size() , (row+1)*3) ; i++){
                    for (int j = col*3 ; j < min((int) board.size() , (col+1)*3) ; j++){
                        if (board[i][j] == '.') continue;
                        if (freq[board[i][j] - '0'] >= 1) return false;
                        freq[board[i][j] - '0']++;
                    }
                }
            }
        }
        return true;
    }
};