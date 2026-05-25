class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<bool> freq(nums.size()+1);
        vector<int> ans;
        for (int i = 0 ; i < nums.size() ; i++ ){
            if (freq[nums[i]])
                ans.push_back(nums[i]);
            freq[nums[i]] = true;
        }
        for (int i = 1 ; i < freq.size() ; i++ ){
            if (!freq[i])
                ans.push_back(i);
        }
        return ans;
    }
};