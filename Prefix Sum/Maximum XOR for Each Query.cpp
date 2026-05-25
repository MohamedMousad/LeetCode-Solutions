class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int curr = 0 , b = 0;
        for (auto i : nums)
        {
            curr ^= i;
        }
            for (int j = 0 ;  j < maximumBit ; j++)
            {
                b |= 1 <<j;
            }
        for (int i =nums.size() - 1 ; i >= 0 ; i--)
        {
            ans.push_back(b^curr);
            curr ^= nums[i];
        }
        return ans;
    }
};