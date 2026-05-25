class Solution {
public:
    int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == t[j-1]) {
            return dp[i][j] = 0 + helper(i - 1, j - 1, s, t, dp);
        } else {                             // delete                    //Insert               //Replace
            return dp[i][j] = 1 + min(helper(i - 1, j, s, t, dp),min(helper(i, j - 1, s, t, dp),helper(i - 1, j - 1, s, t, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        // int answer = helper(n,m, word1, word2, dp);

        //Preparing the Base Case
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=1;j<=m;j++) dp[0][j] = j;
 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = 0 + dp[i-1][j-1];
                } else {               // delete       //Insert     //Replace
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
 
        return dp[n][m];
    }
};