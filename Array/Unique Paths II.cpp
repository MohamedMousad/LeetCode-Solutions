class Solution {
    int dp[101][101] = {};
    int rec(int i , int j , int m , int n , vector<vector<int>>& obstacleGrid){
        if (i == m-1 && j == n-1 && obstacleGrid[i][j] != 1)
            return 1;
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;
        if (~dp[i][j] ) return dp[i][j];
        return dp[i][j] = rec(i+1 , j , m , n , obstacleGrid) +  rec(i, j + 1 , m , n , obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        memset(dp , -1 , sizeof dp);
        return rec(0 , 0 , obstacleGrid.size() , obstacleGrid[0].size() , obstacleGrid );
    }
};