class Solution {
    vector<int> dp ;
    int f = 0;
    int rec(int i ,  vector<int>& costs){
        if (i == f) return 0;
        int& ret = dp[i];
        if (ret != INT_MAX) return ret;
        int ch = INT_MAX;
        if (i+1 <= f)
            ch = min(ch , rec(i+1 , costs) + costs[i] + 1  );
        if (i+2 <= f)
            ch = min(ch , rec(i+2 , costs) + costs[i+1] + 4  );
        if (i+3 <= f)
            ch = min(ch , rec(i+3 , costs) + costs[i+2] + 9  );
        return ret = ch;
            
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        f = n;
        dp.assign(n+5 , INT_MAX);
        return rec(0 , costs);
    }
};