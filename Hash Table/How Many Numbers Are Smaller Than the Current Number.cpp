class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin() , temp.end());
        vector<int> ans(temp.size() , 0) , ans2(nums.size(),  0);
        for (int i = 0 ; i < temp.size() ; i++){
            ans[i] = lower_bound(temp.begin() , temp.end() , temp[i]) - temp.begin();
        }
        for (int i = 0 ; i < nums.size() ; i++){
            ans2[i] = ans[lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin()];
        }
        return ans2;
    }
};