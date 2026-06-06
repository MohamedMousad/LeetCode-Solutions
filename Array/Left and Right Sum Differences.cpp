class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res;
        int sum = 0, curr = 0;
        for (int i= 0 ; i < nums.size() ; i++)
            sum+=nums[i];

        for (int i = 0 ; i < nums.size() ; i++){
            sum-=nums[i];
            res.push_back(abs(curr - sum));
            curr+=nums[i];
        }
        return res;
    }
};