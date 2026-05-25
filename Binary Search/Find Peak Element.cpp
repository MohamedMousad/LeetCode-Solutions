class Solution {
public:
    bool is_good(vector<int>& nums , int mid)
    {
        if (nums.size() == 1) 
            return true;
        if (mid == nums.size()-1)
            return nums[mid - 1] < nums[mid];
        if (mid == 0) 
            return nums[mid + 1] < nums[mid];
        return (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]);
    }
    int BS (vector<int>& nums)
    {
        int l = 0 , r = nums.size()-1 , mid = 0;
        while(l<=r )
        {
            mid = l + (r-l)/2;
            if(is_good(nums , mid))
            {
                return mid;
            }
            else
            {
                if (mid == nums.size()-1)
                {
                    r = mid - 1;
                    continue;
                }
                if (mid == 0)
                {
                    l = mid + 1;
                    continue;
                } 
                if( nums[mid+1] < nums[mid-1])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return mid;
    }
    int findPeakElement(vector<int>& nums) {
        return BS(nums) ;
    }
};