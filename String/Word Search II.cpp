class Solution {
    class WordDictionary {
    public:
        map<char , WordDictionary*> dict;
        int dx[4] = {1 , -1 , 0  , 0 };
        int dy[4] = {0 , 0 , -1, 1};
        bool vis[13][13] = {};
        WordDictionary() {}

        void addWords(int i , int j , int sz, vector<vector<char>>& board , WordDictionary* curr = nullptr) {
            if (sz >= 10) return;
            if (!curr) curr = this;
            vis[i][j] = true;
            if (curr->dict.count(board[i][j]) == 0)
                curr->dict[board[i][j]] = new WordDictionary();
            for (int k = 0 ; k < 4 ; k++){
                int nx = i + dx[k] , ny = j + dy[k];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !vis[nx][ny])
                    addWords(nx, ny , sz+1 , board , curr->dict[board[i][j]]);
            }
            vis[i][j] = false;
        }

        bool search(const string& word , WordDictionary* curr = nullptr) {
            if (!curr)
                curr = this;
            for (int i = 0 ; i < word.size(); i++){
                if (curr->dict.count(word[i]) == 0)
                    return false;
                curr = curr->dict[word[i]];
            }
            return true;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto trie = new WordDictionary();
        for (int i =  0 ; i < board.size() ; i++){
            for (int j = 0 ; j < board[0].size() ; j++){
                trie->addWords(i , j , 0 , board);
            }
        }
        vector<string> res;
        for (int i = 0 ; i< words.size() ; i++){
            if (trie->search(words[i]))
                res.emplace_back(words[i]);
        }
        return res;
    }
};