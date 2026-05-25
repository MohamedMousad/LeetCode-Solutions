class Solution {
    unordered_map<int, vector<int>> mp;
    int abs(int val){
        return val < 0 ? -val : val;
    }
    int calc_cost(int left , int right , int sz){
        if (left > right )
            swap(left , right);
        return min(abs(left - right) , abs(left + (sz - right)));
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        for (int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(queries.size() , -1);
        for (int i = 0 ;i < queries.size() ; i++){
            int idx = queries[i] , val = nums[idx];
            if (mp[val].size() <= 1) continue;
            int location = lower_bound(mp[val].begin() , mp[val].end() , idx) - mp[val].begin();
            int right = mp[val][(location + 1)%mp[val].size()] , 
            left = mp[val][location - 1 < 0 ? mp[val].size() - 1 : location - 1];
            ans[i] = min(calc_cost(left , idx , nums.size()) , calc_cost(right , idx , nums.size()) );
        }
        return ans;
    }
};