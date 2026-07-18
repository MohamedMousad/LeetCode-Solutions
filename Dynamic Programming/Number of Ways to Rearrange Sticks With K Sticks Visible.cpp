class Solution {
    long long dp[1005][1005]= {};
    int mod = 1e9 + 7;
    long long rec(int n , int k){
        if (k == 0 && n == 0) 
            return 1;
        if (n <= 0 || k < 0) return 0;
        long long& ret = dp[n][k];
        if (~ret) return ret;
        long long take = rec(n-1 , k-1);
        long long leave = ((n-1)*rec(n-1 , k))%mod;
        return ret = (take%mod + leave%mod)%mod;
    }
public:
    int rearrangeSticks(int n, int k) {
        memset(dp , -1, sizeof dp);
        return rec( n ,k );
    }
};