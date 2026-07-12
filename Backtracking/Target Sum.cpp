class Solution {
    int dp[25][3005];
    const int shift = 1001;
    int rec(vector<int>& nums, int target , int i, int sum = 0 ){
        int& ret = dp[i][sum+shift];
        if(i >= nums.size()){
            if (sum == target)
                return ret = 1;
            return ret = 0;
        }
        if (~ret)
            return ret;
        return ret = rec(nums , target , i+1 , sum + nums[i]) + rec(nums , target , i+1 , sum - nums[i]) ;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof dp);
        return rec(nums , target , 0 , 0);
    }
};