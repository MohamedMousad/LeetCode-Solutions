class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0 , l = 0 , n = nums.size() , ans = 0;
        while (r < n){
            if (nums[r] - nums[l] == 1){
                ans = max(ans , r - l +1);
                r++;
            }
            else if (nums[r] - nums[l] < 1){
                r++;
            }
            else if (nums[r] - nums[l] > 1 ){
                l++;
            }
        }
        return ans;
    }
};