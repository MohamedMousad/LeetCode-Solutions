class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0 , ans = -INT_MAX ,n =  nums.size();
        for (int i = 0; i < nums.size() ; i++){
            sum = max(sum + nums[i] , nums[i]);
            ans =max(sum , ans);
        }
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        sum = pre[0];
        for (int i = 1 ; i < n ;i++){
            sum+=nums[i];
            pre[i] = max(pre[i-1], sum);
        }
        sum = suf[n-1];
        for (int i = n-2 ; i >= 0 ;i--){
            sum+=nums[i];
            suf[i] = max(suf[i+1], sum);
        }
        for (int i = 0; i < n ; i++){
            int curr = pre[i];
            if (i < n - 1 )
                curr+=suf[i+1];
            ans = max(ans , curr);
        }
        return ans;
    }
};