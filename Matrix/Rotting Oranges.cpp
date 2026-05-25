class Solution {
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    bool vis[11][11] = {};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , ans = 0;
        queue<pair<pair<int,int> , int>> q;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 2)
                    q.push({{i , j} , 0}) , vis[i][j] = 1;
            }
        }
        while (!q.empty()){
            pair<pair<int,int> , int> front = q.front();
            q.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nx = dx[i] + front.first.first , ny = dy[i] + front.first.second;
                if (nx < m && nx >= 0 && ny < n && ny >= 0 && grid[nx][ny] == 1 &&  !vis[nx][ny])
                    q.push({{nx , ny} , front.second + 1}) , vis[nx][ny] = 1;
            }
            ans = max(ans , front.second);
        }
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;
            }
        }
        return ans;
    }
};