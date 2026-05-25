class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -2e4; 
        int sum = 0 ;
        nums.push_back(-1e5);
        for (int l = 0 , r= 0 ; r < nums.size() ;){
            while (r < k && r < nums.size() )
                sum+=nums[r++];
            ans = max(ans , (double)(sum) / k);
            sum-=nums[l++];
            if (r < nums.size())
                sum+=nums[r++];
        }
        return ans;
    }
};