class Solution {
    vector<vector<vector<int>>> dp;
    int n , m , mod = 1e9+7;
    int rec(int i , int j , int dir , vector<vector<int>>& grid){
        if (i >= n || j >= m) return 0;
        if (i == n-1 && j == m-1) return 1;
        int& ret = dp[dir][i][j];
        if (~ret) return ret;
        if (grid[i][j] == 1){
            if (dir == 1)
                return ret = rec(i , j+1 , 0 , grid)%mod;
            else
                return ret = rec(i+1 , j , 1, grid)%mod;
        }
        else{
            int ch1 = rec(i+1 , j , 1, grid)%mod , ch2 = rec(i, j+1 , 0, grid)%mod;
            return ret = (ch1 + ch2)%mod;
        }
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        dp.resize(3);
        for (int i = 0 ; i < 3; i++) dp[i].resize(n+5);
        for (int  i = 0 ; i < n + 5 ; i++)
            dp[0][i].assign(m+5 , -1) , dp[1][i].assign(m+5 , -1) , dp[2][i].assign(m+5 , -1);
        return rec(0 , 0 , 2 , grid);
    }
};