class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0 , ones = 0, ans = 0;
        for (int l = 0 , r = 0 ; r < nums.size() ; r++){
            if (nums[r] == 0)
                zeros++;
            else if (nums[r] == 1)
                ones++;
            while (zeros > 1){
                if (nums[l] == 0)
                    zeros--;
                else if (nums[l] == 1)
                    ones--;
                l++;
            }
            ans = max(ans , ones);
        }
        return (ans == nums.size() ? ans - 1 : ans );
    }
};