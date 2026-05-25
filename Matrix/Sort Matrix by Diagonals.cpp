class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = n-2; i >= 0 ;i--) {
            vector<int> a;
            for(int j = 0, row = i; j < n && row < n; j++ , row++)
                a.push_back(grid[row][j]);
            sort (a.rbegin() , a.rend());
            for(int j = 0, row = i; j < n && row < n; j++ , row++)
                grid[row][j] = a[j];
        }
        for (int j = 1 ; j < n - 1 ; j++){
            vector<int> a;
            for (int i = 0, col = j ; i < n && col < n ; i++ , col++)
                a.push_back(grid[i][col]);
            sort (a.begin() , a.end());
            for (int i = 0, col = j ; i < n && col < n ; i++ , col++)
                grid[i][col] = a[i];
        }
        return grid;
    }
};