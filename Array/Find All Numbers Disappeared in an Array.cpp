class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<bool> freq(nums.size()+1);
        for (auto& i : nums){
            freq[i] = true;
        }
        for (int i = 1 ; i < freq.size() ; i++ ){
            if(!freq[i])
                ans.push_back(i);
        }
        return ans;
    }
};