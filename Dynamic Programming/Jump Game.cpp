class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() , curr = nums[0];
        for (int i  = 1 ; i < n ; i++ ){
            curr--;
            if (curr < 0) return false;
            curr = max(curr , nums[i]);
        }
        return true;
    }
};