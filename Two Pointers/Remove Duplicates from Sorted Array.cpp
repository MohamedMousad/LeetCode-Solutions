class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        vector<int> new_nums;
        for (int i = 0 ; i < nums.size() ;){
            new_nums.push_back(nums[i]);
            while (i < nums.size() && new_nums.back() == nums[i])
                i++;
            ans++;
        }
        nums.swap(new_nums);
        return ans;
    }
};