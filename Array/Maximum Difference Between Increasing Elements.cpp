class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> suf(nums.size());
        for (int i =  nums.size() - 1 ; i >= 0 ; i--){
            if (i == nums.size() - 1) suf[i] = nums[i];
            else suf[i] = max(nums[i] , suf[i+1]);
        }
        int ans = -1 , mn = nums[0];
        for (int i = 1 ; i < nums.size() ; i++){
            if (mn < suf[i])
                ans = max(ans , suf[i] - mn);
            mn = min(nums[i] , mn);
        }
        return ans;
    }
};