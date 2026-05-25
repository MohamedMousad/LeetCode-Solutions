class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1 ; i < nums.size() ; i++){
            if (nums[i-1] != i)
                return false;
        }
        if (nums.size() < 2 || nums[nums.size() - 1] != nums[nums.size() - 2])
            return false;
        return true;
    }
};