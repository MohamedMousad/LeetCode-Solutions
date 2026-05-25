class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1 ; i < nums.size() - 1 ;){
            int j = i-1;
            while (j > 0 && nums[i] == nums[j]){
                j--;
            }
            int left = nums[j];
            j = i+1;
            while (j < nums.size() - 1 && nums[i] == nums[j]){
                j++;
            }
            int right = nums[j];
            if ((nums[i] < left && nums[i] < right) || (nums[i] > left && nums[i] > right)) cnt++;
            i = j;
        }
        return cnt;
    }
};