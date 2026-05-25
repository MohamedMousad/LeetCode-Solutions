class Solution {
public:
    #define ll long long
    const int mod = 1e9 + 7;
    ll powmod(ll x, ll y)
    {
        ll res = 1;
        x = x % mod;
        if (x == 0) return 0;
        while (y > 0)
        {
            if (y & 1)
                res = (res*x) % mod;
            y = y>>1;
            x = (x*x) % mod;
        }
        return res;
    }
    ll add(ll a,ll b)
    {
        return ((a%mod)+(b%mod))%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size() , ans = 0 , l = 0 , r = n-1;
        while (l <= r) {
            while (l <= r && nums[l] + nums[r] > target) {
                r--;
            }
            if (r >= l) {
                ans = add(ans , powmod(2 , r-l));
            }
            l++;
        }
        return ans;
    }
};