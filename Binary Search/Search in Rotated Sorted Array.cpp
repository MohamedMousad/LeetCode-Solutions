class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 1 ; i < nums.size() ; i++){
            if (nums[i] < nums[i-1]){
                auto it = lower_bound(nums.begin() + i , nums.end() , target);
                auto it2 = lower_bound(nums.begin() , nums.begin() + i - 1 , target);
                if (it != nums.end() && *it == target)
                    return (int)(it - nums.begin());
                if (it2 != nums.end() && *it2 == target)
                    return (int)(it2 - nums.begin());
                return -1;
            }
        }
        auto lastCheck = lower_bound(nums.begin() , nums.end() , target);
        return (lastCheck != nums.end() && *lastCheck == target ? (int)(lastCheck - nums.begin()) : -1);
    }
};