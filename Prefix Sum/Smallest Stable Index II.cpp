class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        stack<int> mns ;
        int mn  = 1e9 + 9 , mx = -1; 
        for (int i = nums.size() - 1 ; i >= 0 ; i--){
            mn = min(nums[i] , mn);
            mns.push(mn);
        }
        for (int i = 0 ; i < nums.size() ; i++){
            mx = max(mx , nums[i]);
            if (mx - mns.top()  <= k)
                return i;
            mns.pop();
        }
        return -1;
    }
};