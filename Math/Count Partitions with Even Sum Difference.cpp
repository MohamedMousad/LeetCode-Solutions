class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> suf(nums.size());
        for (int i = nums.size() - 1 ; i >= 0 ; i--){
            if (i == nums.size() - 1)
                suf[i] = nums[i];
            else 
                suf[i] = suf[i+1] + nums[i];
        }
        int sum = 0, cnt = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
            if (i < nums.size() -1 && (suf[i+1] - sum )%2 == 0 )
                cnt++;
        }
        return cnt;
    }
};