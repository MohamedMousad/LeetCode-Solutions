class Solution {
    int BS(vector<int>& nums){
        int l = 0 , r = nums.size()-1 , ans = nums[l];
        while (l <= r){
            int mid = l + ((r-l)>>1);
            if (nums[mid] > nums[r])
                l = mid+1;
            else 
                r = mid - 1;
            ans = min(ans , nums[mid]);
        }
        return ans;
    }
public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums[nums.size() - 1]) return nums[0];
        return BS(nums);
    }
};