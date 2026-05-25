class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int l = 0 , r = 0 , sum = 0 , ans = 0;
        while (r < nums.size()){
            freq[nums[r]]++;
            sum+=nums[r];
            while (freq[nums[r]] > 1ll  && l < r){
                freq[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            ans = max(ans , sum);
            r++;
        }
        return ans;
    }
};