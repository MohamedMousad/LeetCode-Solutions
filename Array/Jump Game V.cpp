class Solution {
    int dp[1000] = {};
    int lim = 0;
    int rec (int i ,vector<int>& arr ){
        int& ret = dp[i];
        if (~ret) return ret;
        int mx = 1;
        for (int curr = i + 1 ; curr <= min(i+lim ,(int) (arr.size() - 1) ) && arr[i] > arr[curr]; curr++)
            mx = max(rec(curr , arr) + 1 , mx);
        for (int curr = i - 1; curr >= max((int) 0 , i - lim) && arr[i] > arr[curr]; curr--)
            mx = max(rec(curr , arr) + 1 , mx);
        return dp[i] = mx;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        memset(dp , -1 , sizeof dp);
        lim = d;
        int mx = 0;
        for (int i = 0 ; i < arr.size() ; i++)
            mx = max(mx , rec(i , arr));
        return mx;
    }
};