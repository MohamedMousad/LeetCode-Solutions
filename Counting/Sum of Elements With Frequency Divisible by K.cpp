class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
       int freq[101] = {};
       for (int i = 0 ; i < nums.size() ; i++){
        freq[nums[i]]++;
       } 
       int ans = 0;
       for (int i = 0 ; i < 101 ; i++){
            ans +=(freq[i] % k == 0? (freq[i]*i): 0);
       } 
       return ans;
    }
};