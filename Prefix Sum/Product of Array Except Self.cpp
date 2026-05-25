class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int l = 1;
        int r = 1;
        vector<int> pre(n), suff(n);

        for(int i = 0; i < n; i++){

            pre[i] = l*nums[i];
            l = pre[i];

            suff[n-1-i] = r*nums[n-1-i];
            r = suff[n-1-i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){

            if(i == 0) ans[i] = suff[i+1];
            else if(i == n-1) ans[i] = pre[i-1];
            else ans[i] = pre[i-1]*suff[i+1];
        }

        return ans;
        
    }
};