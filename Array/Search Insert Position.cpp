class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1 , mid = 0;
        while (l <= r ){
            mid = l + ((r- l)>>1);
            if (nums[mid] > target ) r = mid - 1;
            else if (nums[mid] < target ) l = mid + 1;
            else return mid;
        }
        return l;
    }
};