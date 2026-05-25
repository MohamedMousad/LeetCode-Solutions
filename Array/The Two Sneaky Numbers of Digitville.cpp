class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        bool freq[105] = {};
        vector<int> ans;
        for (auto& num : nums){
            if (freq[num]) ans.push_back(num);
            freq[num] = true;
        }
        return ans;
    }
};