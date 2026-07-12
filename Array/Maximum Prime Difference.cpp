class Solution {
    bool is_prime(int n)
    {
        if(n==1||n==0)return 0;
        else if(n==2)return 1;
        else if(n%2==0)return 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)return 0;
        }
        return 1;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = 0 , last = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            if (is_prime(nums[i])){
                first = i ;
                break;
            }
        }   
        for (int i = nums.size() - 1 ; i >= 0 ; i--){
            if (is_prime(nums[i])){
                last = i ;
                break;
            }
        }
        return last - first;
    }
};