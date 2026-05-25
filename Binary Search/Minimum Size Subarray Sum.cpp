class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size() , sum = 0;
        bool any = 0;
        for (int l = 0 , r= 0 ; r < nums.size() ; r++){
            sum+=nums[r];
            while ( sum - nums[l] >= target )
                sum-=nums[l++];
            if (sum >= target)
                any = 1, sz = min(r - l + 1 , sz);
        }
        return (any? sz : 0);
    }
};