class Solution {
    int sz ;
    int dp[601][101][101];
    vector<pair<int,int>> counts;
    int rec (int i  ,int m , int n ){
        if (i == sz) return 0;
        if (~dp[i][m][n]) return dp[i][m][n];
        int ch1 = 0 , ch2 = 0;
        if (counts[i].first <= m && counts[i].second <= n )
            ch1 = rec(i+1 , m - counts[i].first , n - counts[i].second) + 1;
        ch2 = rec(i+1, m , n);
        return dp[i][m][n] = max(ch1 , ch2);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        sz = strs.size();
        memset(dp , -1 , sizeof dp);
        counts.resize(sz);
        for (int i = 0 ;i < sz ; i++){
            int cnt1 = 0 , cnt0 = 0 ;
            for (int j = 0 ; j < strs[i].size() ; j++){
                if (strs[i][j] == '0') cnt0++;
                else cnt1++;
            }
            counts[i] = {cnt0 , cnt1};
        }
        return rec( 0 , m , n);
    }
};