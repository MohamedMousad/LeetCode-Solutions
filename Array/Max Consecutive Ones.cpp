class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for (int i = 0 ; i < nums.size() ; ){
            int cnt = 0;
            while (i < nums.size() && nums[i] == 1) cnt++ , i++;
            ans = max(ans , cnt);
            i+=(cnt == 0);
        }
        return ans;
    }
};