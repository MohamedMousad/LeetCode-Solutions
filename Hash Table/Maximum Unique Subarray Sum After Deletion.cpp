class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<bool> freq(101 , 1);
        short sum = 0;
        bool flag = 0;
        for (auto& num : nums){
            if (num > 0 && freq[num]){
                freq[num] = false;
                flag = 1;
                sum+=num;
            }
        }
        if(!flag){
            return *max_element(nums.begin() , nums.end());
        }
        return sum;
    }
};