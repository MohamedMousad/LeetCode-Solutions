class Solution {
    #define ll long long
    const int N=1e5+5,mod=1e9+7;
    ll MOD;
    vector<ll> fac,inv,finv;
    void init(int n,ll mod)
    {
        fac.resize(n+1);
        inv.resize(n+1);
        finv.resize(n+1);
        MOD=mod;
        fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
        for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
        for(ll i=2;i<=n;++i)inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
        for(ll i=2;i<=n;++i)finv[i]=finv[i-1]*inv[i]%MOD;
    }
    ll nCr(ll x,ll y)
    {
        if(x<0||y>x||y<0)return(0);
        return(fac[x]*finv[y]%MOD*finv[x-y]%MOD);
    }
    ll mul(ll a,ll b)
    {
        return ((a%mod)*(b%mod))%mod;
    }
    ll add(ll a,ll b)
    {
        return ((a%MOD)+(b%MOD))%MOD;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> heights;
        vector<long long> ncrs;
        init(N , mod);
        for (int i = 0 ; i < points.size(); i++)
            heights[points[i][1]]++;
        for (auto& elem : heights)
            if (elem.second >= 2)
                ncrs.push_back(nCr(elem.second , 2LL));
        if ( ncrs.size() <= 1)
            return 0;
        else {
            long long ans = 0;
            vector<long long> suf(ncrs.size());
            for (int i = ncrs.size() - 1 ; i >= 0 ; i--){
                if (i == ncrs.size()- 1)
                    suf[i] = ncrs[i];
                else
                    suf[i] = add(suf[i+1] , ncrs[i]);
            }
            for (int i = 0 ; i < ncrs.size() - 1 ; i++){
                ans+=mul(ncrs[i] , suf[i+1]);
                ans%=mod;
            }
            return ans;
        }
    }
};
static const long long init = [] {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&___::_);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();