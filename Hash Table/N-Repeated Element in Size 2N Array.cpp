class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for (int i = 0 ; i < nums.size() ; i++){
            if (mp[nums[i]])
                return nums[i];
            mp[nums[i]] = true;
        }
        return 0;
    }
};