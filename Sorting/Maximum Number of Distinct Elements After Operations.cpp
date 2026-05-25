class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int good = 0;
        int last = nums[0] - k;
        for (int i = 0 ; i < nums.size() ; i++){
            last = max(nums[i] - k , last);
            if (abs(last - nums[i]) <= k )
                good++ , last++;
        }
        return good;
    }
};