class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt= 0;
        for (int i = 0 ; i < grid.size() ; i++){
            int mx = 0;
            for (int j = 0 ; j < grid.size() ; j++){
                mx = max(grid[i][j] , mx);
                if (grid[i][j])
                    cnt++;
            }
            cnt+=mx;
        }
        for (int i = 0 ; i < grid.size() ; i++){
            int mx = 0;
            for (int j = 0 ; j < grid.size() ; j++){
                mx = max(grid[j][i] , mx);
            }
            cnt+=mx;
        }
        return cnt;
    }
};