class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int mx = -1;
        for (int i = 0 ; i < nums.size() ;i++){
            if (nums[i] != i){
                if (mx == -1) mx = nums[i];
                else mx&=nums[i];
            }

        }
        if (mx == -1) mx = 0;
        return mx;
    }
};