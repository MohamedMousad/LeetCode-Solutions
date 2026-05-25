class Solution {
    bool vis[101][101] = {};
    int dx[4] = {0 , 0 , -1 , 1};
    int dy[4] = { -1 , 1 , 0, 0};
    int rec(int i , int j , vector<vector<int>>& grid){
        vis[i][j] = true;
        int sum = 0 , cnt = 0;
        for (int k = 0 ; k < 4 ; k++){
            int nx = i + dx[k] , ny = j + dy[k];
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny]){
                cnt++;
                if (!vis[nx][ny])
                    sum += rec(nx , ny , grid);
            }
        }
        sum += (4 - cnt);
        return sum ;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0 ; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[0].size() ; j++){
                if (grid[i][j])
                    return rec(i ,  j , grid);
            }
        }
        return 0;
    }
};