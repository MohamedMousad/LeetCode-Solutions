class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int last_vis = -1;
        for (int i = 0 ; i < nums.size();i++){
            if (nums[i] == key){
                for (int j = max(i - k , last_vis + 1) ; j <= min(i+k , (int) (nums.size()) - 1) ; j++){
                    if (nums[j] == key && j > i ) i = j;
                    ans.push_back(j);
                }
                i+=k;
                last_vis = i;
            }
        }
        return ans;
    }
};