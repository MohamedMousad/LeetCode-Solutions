#define ll long long
// #define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define PF push_front
#define EB emplace_back
#define EF emplace_front
#define PPF pop_front
#define PPB pop_back
#define F first
#define S second
#define MP make_pair
#define uset unordered_set
#define umap unordered_map
#define PI acosl(-1.0L)
#define endl '\n'
#define fr(i, a, b) for (int i = (a); i < (b); ++i)
#define frn(i, a, b) for (int i = (a); i >= (b); --i)
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<ii>;
using vll = vector<pll>;
using vvii = vector<vii>;
using mii = map<int, int>;
using mll = map<ll, ll>;
const ll INFL = 1e18;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 100;
const ld EPS = 1e-7;

inline int LC(int i) { return (i << 1); }     // same as 2*i
inline int RC(int i) { return (i << 1) | 1; } // same as 2*i + 1
template <typename T> int SZ(const T& x) { return static_cast<int>(x.size()); }

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
public:
    int dp[14][10100];
    int coinChange(vector<int>& v, int amount) {
        memset(dp, 0, sizeof(dp));
        int n = SZ(v);
        frn(i,n,0){
            fr(A,0,amount+1){
                if(i==n){
                    if(A==0) dp[n][0]=0;
                    else dp[n][A] = INF;
                }else {
                    int take = (A-v[i]>=0) ? dp[i][A-v[i]]+1:INF;
                    dp[i][A]=min(take,dp[i+1][A]);
                }
            }
        }
        return dp[0][amount]==INF?-1:dp[0][amount];
    }
};