class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int start = nums[0] , cnt = 0;
        for (int i = 0 ; i < nums.size() ;){
            while (i < nums.size() && nums[i] - start <= k){
                i++;
            }
            start = nums[i];
            cnt++;
        }
        return cnt;
    }
};