class Solution {
    int dp[101][101] = {};
    bool rec(string& s1, string& s2, string& s3 , int i , int j , int k){
        if (i == s1.size() && j == s2.size() && k == s3.size()) return 1;
        if (~dp[i][j]) return dp[i][j];
        bool ch1 = false;
        if (i < s1.size() && s3[k] == s1[i]) ch1 |=rec(s1 , s2 , s3 , i + 1, j , k + 1 );
        if (j < s2.size() && s3[k] == s2[j]) ch1 |=rec(s1 , s2 , s3 , i, j + 1 , k + 1 );
        return dp[i][j] = ch1;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp , -1 , sizeof dp);
        return rec(s1 , s2 ,s3 , 0 , 0 , 0);
    }
};