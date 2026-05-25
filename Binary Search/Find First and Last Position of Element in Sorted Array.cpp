class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin() , nums.end() , target);
        return ((it == nums.end() || *it != target) ? std::vector<int>{-1 , -1} : 
                std::vector<int>{ (int)(it - nums.begin() ), (int)(upper_bound(nums.begin() , nums.end() , target) - nums.begin() - 1) });
    }
};