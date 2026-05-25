class Solution {
public:
    bool check(vector<int>& nums) {
        bool ans = false;
        int mn = nums[0];
        for (int i = 0 ; i < nums.size(); i++){
            if (i < nums.size() - 1 && ans && nums[i] > nums[i+1])
                return false;
            if (ans && nums[i] > mn )
                return false;
            if (i < nums.size() - 1)
                ans |= (nums[i] > nums[i+1]);
        }
        return true;
    }
};