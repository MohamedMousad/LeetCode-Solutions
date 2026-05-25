class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool freq[100006]= {};
        for (int i = 0 ; i < nums.size(); i++)
            if (nums[i] > 0 && nums[i] < 1e5 + 5)
                freq[nums[i]] = true;

        for (int i = 1; i<= 1e5 + 5; i++)
            if (!freq[i])
                return i;
        return -1;
    }
};