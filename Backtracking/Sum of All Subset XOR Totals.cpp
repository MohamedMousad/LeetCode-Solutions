class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int limit = (1 << nums.size());
        for (int msk = 0 ; msk < limit ; msk++)
        {
            int curr = 0;
            for (int i = 0 ; i < nums.size();i++)
            {
                if (msk & 1<<i)
                {
                    curr ^= nums[i];
                }
            }
            sum+=curr;
        }
        return sum;
    }
};