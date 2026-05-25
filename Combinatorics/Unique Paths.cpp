class Solution {
    int dp[101][101] = {};
    int rec (int i , int j , int m , int n  ){
        if (i == m-1 && j == n-1)
            return 1;
        if (~dp[i][j]) return dp[i][j];
        int ans = 0;
        if (i+1 < m)
            ans+=rec(i+1 , j , m , n);
        if (j+1 < n)
            ans+=rec(i , j+1 , m , n);
        return dp[i][j] = ans;
    } 
public:
    int uniquePaths(int m, int n) {
        memset(dp  , -1 , sizeof dp);
        return rec(0 , 0 , m , n);
    }
};