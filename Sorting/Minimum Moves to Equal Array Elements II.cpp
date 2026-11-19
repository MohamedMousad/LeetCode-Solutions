class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long pre = 0 , suf = 0 , sz = nums.size() , ans = LLONG_MAX;
        for (int i = 0 ; i < nums.size(); i++) suf+=nums[i];
        for (int i = 0 ; i < nums.size(); i++) {
            ans = min(ans , ((long long)nums[i]*i - pre) + (suf - ((long long)nums[i]*(sz-i))) );
            pre+=nums[i];
            suf-=nums[i];
        }
        return ans;
        
    }
};