class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int sum = 0 ,  n = nums.size();
        vector<bool> ans(n);
        for (int i = 0 ; i < n ; i++){
            sum%=5;
            sum+=nums[i];
            ans[i] = (sum%5 == 0);
            sum <<=1;
        }
        return ans;
    }
};