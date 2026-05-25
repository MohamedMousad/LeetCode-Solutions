class Solution {
    int rec (vector<vector<int>>& grid , vector<vector<int>>& dp , int i , int j){
        if (i == grid.size() && j == grid[0].size() - 1 || 
            i == grid.size() - 1 && j == grid[0].size()) 
            return 0;

        if (i >= grid.size() || j >= grid[0].size()) 
            return 1000000;
        if (~dp[i][j]) 
            return dp[i][j];
        int ch1 = 0 , ch2 = 0;
        ch1 = rec(grid , dp , i , j+1 ) + grid[i][j];
        ch2 = rec(grid , dp , i + 1 , j) + grid[i][j];
        return dp[i][j] = min(ch1 , ch2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size() + 5 , vector<int>(grid[0].size() + 5 , -1));
       return rec(grid , dp , 0 , 0); 
    }
};