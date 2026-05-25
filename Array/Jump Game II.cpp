#include <bits/stdc++.h>
class Solution {
public:
    int dp[10005];
    int rec(int i , vector<int>& nums){
        if (i == nums.size()-1) return 0; 
        int& ret = dp[i];
        if (~ret) return ret;
        int ch = 100000;
        for (int j = 1 ; j <= (nums[i] < nums.size()-i-1? nums[i] : nums.size()-i-1)  ; j++){
            ch = min(rec(i + j , nums) + 1, ch);
        }
        return ret = ch;
    }
    int jump(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return rec(0 , nums);
    }
};