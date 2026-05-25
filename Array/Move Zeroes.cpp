class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int l = 0 , r = 0 ; r < nums.size() && l < nums.size(); r++){
            if (nums[r] != 0){
                while (l < r && nums[l] != 0)
                    l++;
                if ( l < nums.size() )
                    swap(nums[l] , nums[r] );
            }
        }
        return ;
    }
};