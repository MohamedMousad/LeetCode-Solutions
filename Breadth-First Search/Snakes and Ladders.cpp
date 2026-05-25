class Solution {
    int vis[40][40] = {};
    int n;
    const int k = 1;
    pair<int,int> get_pos(int i){
        int row = n - (i / n )- (i%n != 0) , 
        col = (((n - 1 - row)%2 == 0) ? ((i - 1) % n) : (n - 1 - ((i - 1 )% n))) ;
        return {row , col};
    }
    int bfs(int start ,vector<vector<int>>&  board){
        queue<pair<int,int>> cells;
        vis[n-1][0]++;
        cells.push({start , 0});
        while (!cells.empty()){
            auto front = cells.front();
            auto origin = get_pos(front.first);
            vis[origin.first][origin.second]++;
            cells.pop();
            if (front.first == n*n)
                return front.second;
            for (int i = front.first + 1 ; i < min(front.first + 7 , n*n + 1) ; i++){
                auto loc = get_pos(i);
                if (~board[loc.first][loc.second]){
                    auto loc_ladder = get_pos(board[loc.first][loc.second]);
                    if (!vis[loc_ladder.first][loc_ladder.second])
                        cells.push({ board[loc.first][loc.second] , front.second + 1 });
                }
                else if (vis[loc.first][loc.second] < k)
                    cells.push({i , front.second + 1}) , vis[loc.first][loc.second]++;
            }
        }
        return -1;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        memset(vis , 0 , sizeof vis);
        n = board.size();
        return bfs(1 , board);
    }
};