class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> a ;
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i] != val) a.push_back(nums[i]);
        }
        a.swap(nums);
        return nums.size();
    }
};