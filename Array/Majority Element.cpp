class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0 , n = nums.size();
        if (n < 3) return nums[0];
        for (int i = 0 ; i < n ; i++){
            int cnt = 1;
            while (i < n - 1 && nums[i] == nums[i+1]) i++ , cnt++;
            if (cnt > (n>>1))
                return nums[i-1];
        }
        return nums[n-1];
    }
};