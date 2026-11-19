class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if (nums.size() <= 3) return 0;
        sort(nums.begin() , nums.end());
        int ans = INT_MAX;
        ans = min( nums.back() - nums[2], ans);
        ans = min( nums[nums.size() - 2] - nums[1], ans);
        ans = min( nums[nums.size() - 3] - nums[0], ans);
        return ans;
    }
};