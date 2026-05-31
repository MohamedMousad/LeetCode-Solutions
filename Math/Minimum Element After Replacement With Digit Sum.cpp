class Solution {
    int sumDigits(int num){
        int sum = 0;
        while(num)
            sum+=num%10 , num/=10;
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mn =INT_MAX;
        for (int i = 0 ; i < nums.size() ; i++)
            mn = min(mn , sumDigits(nums[i]));
        return mn;
    }
};