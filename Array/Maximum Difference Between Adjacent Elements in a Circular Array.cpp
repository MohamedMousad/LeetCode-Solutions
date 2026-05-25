class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 1 ; i < nums.size() ; i++){
            mx = max(abs(nums[i] - nums[i-1]) , mx);
        }
        return mx;
    }
};