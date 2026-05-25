class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers , nu;
        vector<int> ans;
        for (int i = 0 ; i < nums.size(); i++){
            ans.push_back(nums[i]);
            if (ans.back() - ans.front() > k)
                return nu;
            if (ans.size() == 3)
            {
                answers.push_back(ans);
                ans.clear();
            }
        }
        return answers;
    }
};