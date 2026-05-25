class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0 , ans = 0;
        for (int i = 1 ; i < nums.size() ; ){
            int r = i , curr = nums[i];
            while (r < nums.size() && nums[r] == nums[r-1]){
                r++;
            }
            if (mx < curr){
                ans = (r - i + 1);
                mx = curr;
            }
            else if (mx == curr){
                ans = max(ans , (r-i+1));
                mx = curr;
            }
            if (r > i)
                i = r ;
            else 
                i++;
        }
        if (nums[0] > mx ){
            return 1;
        }
        return ans;
    }
};