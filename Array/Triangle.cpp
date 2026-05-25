class Solution {
    int dp[201][201] = {};
    int rec (int i , int j , vector<vector<int>>& triangle){
        if (i == triangle.size() ) return 0;
        if (dp[i][j] != 1e9 ) return dp[i][j];
        return dp[i][j]  = min(rec(i+1 , j , triangle) , rec(i+1 , j+1 , triangle)) + triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 0 ; i < triangle.size() ; i++)
            for (int j = 0 ; j < triangle[i].size() ; j++)
                dp[i][j] = 1e9;
        rec (0 , 0 , triangle);
        return dp[0][0];
    }
};