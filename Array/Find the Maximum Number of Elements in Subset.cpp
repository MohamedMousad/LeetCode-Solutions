class Solution {
    unordered_map<int , int> mp , ans;
    int rec (int num , int flag){
        if (mp.count(num) == 0 || mp[num] < flag)
            return 0;
        if (num == 1){
            if (flag == 1){
                int cnt = 1 + ((mp[num] - 1)/2)*2;
                return cnt;
            }
            return (mp[num]/2)*2;
        }
        int next = sqrt(num);
        return (next == sqrt(num) ? flag + rec(next, 2) : flag);
    }
public:
    int maximumLength(vector<int>& nums) {
        int res = 1;
        for (int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            ans[nums[i]] = -1;
        }
        for (int i = 0 ; i < nums.size() ; i++){
            if (ans[nums[i]] == -1){
                ans[nums[i]] = 1;
                res = max(res , rec(nums[i], 1));
            }
        }
        return res;
    }
};