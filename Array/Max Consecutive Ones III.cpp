class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0 = 0 , ans = 0;
        for (int l = 0 , r = 0 ; r < nums.size() ; r++){
            cnt0+=(nums[r] == 0);
            while (cnt0 > k && l <= r )
                cnt0-=(nums[l++] == 0);
            if (cnt0 <= k )
                ans = max(ans , r - l + 1);
        }
        return ans;
    }
};