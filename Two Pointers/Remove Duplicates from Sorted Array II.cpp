class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool flag = 0;
        int r = 1;
        for (int i = 1  ; i < nums.size() ; i++){
            if (nums[i] == nums[r-1] && flag)
                continue;
            flag = (nums[i] == nums[r-1]) , nums[r++] = nums[i];
        }
        return r ;
    }
};