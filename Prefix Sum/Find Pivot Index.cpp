class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0 , curr= 0;
        for (auto& i : nums)
            sum+=i;
        for (int i = 0 ; i < nums.size() ; i++){
            if (curr == sum - nums[i])
                return i;
            sum-=nums[i];
            curr+=nums[i];
        }
        return -1;
    }
};