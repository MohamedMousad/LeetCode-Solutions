class Solution
{
    const int mod = 1e9 + 7;
    long long rec(int i, int j, int &n, vector<vector<long long>> &dp)
    {
        long long &ret = dp[i][j];
        if (~ret)
            return ret;

        if (i == n && j == n)
            return ret = 1LL;

        long long ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0, ch5 = 0, ch6 = 0;

        if (i + 2 <= n && j + 2 <= n && i == j)
            ch1 = rec(i + 2, j + 2, n, dp) % mod;

        if (i + 1 <= n && j + 1 <= n && i == j)
            ch2 = rec(i + 1, j + 1, n, dp) % mod;

        if (i + 2 <= n && j + 1 <= n && (i - j == -1 || j == i))
            ch3 = rec(i + 2, j + 1, n, dp) % mod;

        if (j + 2 <= n && i + 1 <= n && (j - i == -1 || j == i))
            ch4 = rec(i + 1, j + 2, n, dp) % mod;

        if (i + 2 <= n && i < j)
            ch5 = rec(i + 2, j, n, dp) % mod;

        if (j + 2 <= n && j < i)
            ch6 = rec(i , j + 2, n, dp) % mod;
        return ret = ((ch1 % mod) + (ch2 % mod) + (ch3 % mod) + (ch4 % mod) + (ch5 % mod) + (ch6 % mod)) % mod;
    }

public:
    int numTilings(int n)
    {
        vector<vector<long long>> dp(n + 5);
        for (int i = 0; i < n + 5; i++)
            dp[i].assign(n + 5, -1);
        return rec(0, 0, n, dp);
    }
};