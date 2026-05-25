class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int l= 0 , r = nums.size() - 1 ; l < r ; ){
            if (nums[l] + nums[r] > k)
                r--;
            else if (nums[l] + nums[r] < k)
                l++;
            else 
                r-- , l++ , cnt++;
        }
        return cnt;
    }
};