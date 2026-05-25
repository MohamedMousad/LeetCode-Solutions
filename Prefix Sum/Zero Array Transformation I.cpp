class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> freq(nums.size() , 0);
        for (int i = 0 ; i < queries.size() ; i++){
            int l = queries[i][0] , r =  queries[i][1];
            freq[l]--;
            if (r + 1 < nums.size()){
                freq[r+1]++;
            }
        }
        int minus = 0;
        for (int i = 0 ; i < nums.size() ;i++){
            minus+=freq[i];
            if (nums[i] + minus > 0){
                return false;
            }
        }
        return true;
    }
};