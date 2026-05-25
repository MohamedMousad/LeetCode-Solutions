class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 1 , n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> freq(nums.back()+1);
        for (int i = 0 ; i < n ; i++) freq[nums[i]]++;
        int l = 0 , r = 0;
        for (int i = nums[0] ; i <= nums.back() ; i++){
            while (r < n && nums[r] <= i + k) r++;
            while (l < n && nums[l] < i - k) l++;
            ans = max( ans , min (numOperations , (r - l) - freq[i]) + freq[i]);
        }
        return ans;
    }
};