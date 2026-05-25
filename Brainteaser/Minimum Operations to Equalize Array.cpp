class Solution {
public:
    int minOperations(vector<int>& nums) {
        int start = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != start)
                return 1;
        }
        return 0;
    }
};