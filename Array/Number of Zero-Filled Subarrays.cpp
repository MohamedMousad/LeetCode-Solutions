class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 ; 
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            long long cnt = 0;
            while (i < n && nums[i] == 0){
                i++;
                cnt++;
            }
            ans +=((cnt)*(cnt+1)/2);
        }
        return ans;
    }
};