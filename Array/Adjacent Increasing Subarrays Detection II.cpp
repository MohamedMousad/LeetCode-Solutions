class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int last = 0  , last_prev = 0 , ans = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            int mx = 1;
            while ( i + 1 < nums.size() && nums[i] < nums[i+1])mx++ , i++;
            last_prev = last;
            last = mx;
            ans = ( ans < (last>>1) ? (last>>1) : ans );
            ans = ( ans < (last < last_prev ? last : last_prev) ? (last < last_prev ? last : last_prev) : ans);
        }
        return ans;
    }
};