class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx_or = 0 , cnt = 0;
        for (int i = 0 ; i < nums.size(); i++)
            mx_or |= nums[i]; 
        for (int i = 1 ; i < 1 << nums.size(); i++){
            int sum = 0;
            for (int j = 0 ; j < nums.size() ; j++){
                if (i & (1 << j) )
                    sum|=nums[j];
            }
            if (sum == mx_or)
                cnt++;
        }
        return cnt;
    }
};