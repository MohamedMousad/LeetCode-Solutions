class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0] , sum = 0; 
        for (int  i = 0 ; i < nums.size() ; i++) mn = min(nums[i] , mn);
        for (int  i = 0 ; i < nums.size() ; i++) sum+=(abs(mn - nums[i]));
        return sum;
    }
};