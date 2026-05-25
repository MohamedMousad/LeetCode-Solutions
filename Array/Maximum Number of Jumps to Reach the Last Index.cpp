class Solution {
public:
    static int maximumJumps(vector<int>& nums, int target) {
        const int n=nums.size();
        vector<short>dp(n, SHRT_MIN);
        dp[0]=0;
        for(int i=0; i<n; i++){
            const int x=nums[i];
            for (int j=0; j<i; j++) {
                if (abs(nums[j]-x)<=target) {
                    dp[i]=max(dp[i] , (short)(1+dp[j]));
                }
            }
        }
        return  dp[n-1]<0?-1:dp[n-1];
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();