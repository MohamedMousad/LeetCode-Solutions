class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long min1 = 50000000000;
        long long min2 = 50000000000;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > min1 && nums[i] > min2)
                return true;
            if (nums[i] > min1 && nums[i] < min2)
                min2 = nums[i];
            else if (nums[i] < min1)
                min1 = nums[i];
        }
        return false;
    }
};