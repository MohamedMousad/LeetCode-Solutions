class Solution {
    int dp[1001] = {};
    int rec(int  i , vector<int>& cost){
        if (i >= cost.size() ) return 0;
        if(~dp[i]) return dp[i];
        if (i == 0 )
            return dp[i] = min(min(rec(i+1 , cost) + cost[i] , rec(i+2 ,cost) + cost[i]) ,  min(rec(i+2 , cost) + cost[1] , rec(i+ 3 , cost) + cost[1]));
        else
            return dp[i] = min(rec(i+1 , cost) + cost[i] , rec(i+2 ,cost) + cost[i]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof dp);
        return rec(0 , cost);
    }
};