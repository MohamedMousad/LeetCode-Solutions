class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        short last = 0  , last_prev = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            short mx = 1;
            while ( i + 1 < nums.size() && nums[i] < nums[i+1])mx++ , i++;
            last_prev = last;
            last = mx;
            if (last >= (k<<1) || last >= k && last_prev >= k) return true;
        }
        return false;
    }
};