class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long ans = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            if (mp.find(nums[i]) != mp.end()) continue;
            if (mp.find(nums[i] - 1) != mp.end() && mp.find(nums[i] + 1) != mp.end()){
                long long l = mp[nums[i] - 1] , r = mp[nums[i] + 1];
                mp[l] = r;
                mp[r] = l;
                if (r> 0 && l > 0)
                    ans = max(ans , r - l + 1);
                else if (r < 0 && l < 0 )
                    ans = max(ans  , abs(l) - abs(r) + 1);
                else
                    ans = max(ans , abs(r) + abs(l) + 1);
            }
            else if (mp.find( nums[i] - 1) != mp.end()){
                mp[nums[i]] = mp[nums[i] - 1];
                mp[mp[nums[i] - 1]] = nums[i];
                long long l =  mp[nums[i]] , r =  nums[i];
                if (r> 0 && l > 0)
                    ans = max(ans , r - l + 1);
                else if (r < 0 && l < 0 )
                    ans = max(ans  , abs(l) - abs(r) + 1);
                else
                    ans = max(ans , abs(r) + abs(l) + 1);
            }
            else if (mp.find( nums[i] + 1) != mp.end()){
                mp[nums[i]] = mp[nums[i] + 1];
                mp[mp[nums[i]]] = nums[i];
                long long l = nums[i] , r =  mp[nums[i]] ;
                if (r> 0 && l > 0)
                    ans = max(ans , r - l + 1);
                else if (r < 0 && l < 0 )
                    ans = max(ans  , abs(l) - abs(r) + 1);
                else
                    ans = max(ans , abs(r) + abs(l) + 1);
            }
            else
                mp[nums[i]] = nums[i] , ans = max(ans , 1LL);
            if (mp.count(nums[i]) == 0)
                mp[nums[i]] = nums[i];
        }
        return ans;
    }
};