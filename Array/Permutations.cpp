class Solution {
    bool taken[6] = {}; 
    vector<vector<int>> ans;
    vector<int> curr;
    void rec(int i , vector<int>& nums){
        if (curr.size() == nums.size())
            ans.push_back(curr);
        for (int k = 0 ; k < nums.size() ; k++){
            if (!taken[k]){
                taken[k] = 1;
                curr.push_back(nums[k]);
                rec(i+1 , nums);
                curr.pop_back();
                taken[k] = 0;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        rec(0 , nums);
        return ans;
    }
};