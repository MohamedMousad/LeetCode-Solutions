class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mx = INT_MIN;
        for (int sz =  1 ; sz < 33 ; sz++){
            for (int i = 0 ; i < nums.size() ; i++){
                long long num = 1; 
                for (int j = i ; j < min( i + sz , (int)nums.size()) ; j++) {
                    num*=nums[j];
                }
                mx = max(num , mx);
            }
        }
        return mx;
    }
};