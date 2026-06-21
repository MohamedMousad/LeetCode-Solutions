class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            long long sum = 0 ;
            for (int j = i ; j < nums.size() ; j++){
                sum+=nums[j];
                long long sum2 = sum;
                if (sum%10 != x )
                    continue;
                while (sum2 > 9){
                    sum2/=10;
                }
                if (sum2 == x)
                    cnt++;
            }
        }
        return cnt;
    }
};