class Solution {
    int dp[1005][2][101];
    int rec(int i , int buy , int k , vector<int>& prices ){
        if (i == prices.size())
            return 0;
        int& ret = dp[i][buy][k];
        if (~ret) return ret;
        int ch = 0;
        ch = max(ch , rec(i+1 , buy , k , prices));
        if (k > 0 && buy == 0 )
            ch = max(ch , rec(i + 1 , 1 , k-1 , prices ) - prices[i]);
        else if (buy == 1)
            ch = max(ch , rec(i +1 , 0 , k  , prices) + prices[i]);
        return ret = ch;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1 ,sizeof dp);
        return rec(0 , 0 , k , prices);
    }
};