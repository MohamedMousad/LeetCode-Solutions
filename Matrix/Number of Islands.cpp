class Solution {
    int dx [4] = { 0 , 0 , -1 , 1 };
    int dy [4] = { 1 , -1 , 0 , 0 };
public:
    void dfs(vector<vector<char>>& grid , int i , int j){
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] != '1') return;
        grid[i][j] = '0';
        for (int k = 0 ; k < 4 ; k++)
            dfs(grid , i + dx[k] , j + dy[k]);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0 ; i < grid.size() ; i++)
            for (int j = 0 ; j < grid[0].size() ; j++)
                if (grid[i][j] == '1')
                    dfs(grid, i , j) , cnt++;
        return cnt;
    }
};