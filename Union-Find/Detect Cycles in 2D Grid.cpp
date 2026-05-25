class Solution {
    int dx [4] = {1 , -1, 0  ,0 };
    int dy [4] = {0 , 0, -1  ,1 };
    bool rec (int i, int j ,int cnt, char c, vector<vector<char>>& grid , vector<vector<int>>& vis){
        bool ch = false;
        cnt++;
        vis[i][j] = cnt;
        for (int k = 0; k < 4 ; k++){
            int nx = i + dx[k] , ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && c == grid[nx][ny]){
                if (vis[nx][ny] && abs(vis[nx][ny] - vis[i][j]) >= 3) return true; 
                else if (!vis[nx][ny] ) ch |= rec(nx, ny , cnt , c , grid , vis);
            }
            if (ch) return true;
        }
        return ch;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size() , vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[0].size() ; j++){
                if (!vis[i][j] && rec(i , j , 0 , grid[i][j] , grid , vis))
                    return true;
            }
        }
        return false;
    }
};