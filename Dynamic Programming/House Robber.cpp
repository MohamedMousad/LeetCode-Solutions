class Solution {
    int dp[2][101];
    int rec(vector<int>& nums , int i , bool can){
        if (i == nums.size()) return 0;
        if (~dp[can][i]) return dp[can][i];
        int ch1 = 0 , ch2 = 0;
        if (can) ch1 = rec(nums , i+1 , 0 ) + nums[i];
        ch2 = rec(nums , i+1 , 1 );
        return dp[can][i] = max(ch1 , ch2);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp , -1 , sizeof dp);
        return rec(nums , 0  , 1);
    }
};