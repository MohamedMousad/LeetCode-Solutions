class Solution {
#define ll  long long
    ll MOD = 1e9  + 7;
    ll mul(ll a,ll b)
    {
        return ((a%MOD)*(b%MOD))%MOD;
    }
    ll add(ll a,ll b)
    {
        return ((a%MOD)+(b%MOD))%MOD;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long ans = 0 , mx_pre = 0 , mx_suf = 0 , mx_sub = 0 , sum = 0 , sum2 = 0;
        for (int i = 0 ; i < arr.size() ; i++)
            sum+=arr[i] , mx_pre = max(mx_pre , sum);
        sum = 0;
        for (int i = arr.size() - 1 ; i >= 0 ;i--)
            sum+=arr[i] , mx_suf = max(mx_suf , sum);
        for (int i = 0 ; i < arr.size() ;i++){
            sum2+=arr[i];
            sum2 = max(sum2 , 0LL);
            mx_sub = max(mx_sub , sum2);
        }
        long long res = 0;
        if (k >= 1)
            res = max(res , mx_sub);
        if (k >= 2)
            res = max(res , mx_pre + mx_suf);
        if (k >= 3 ) {
            long long curr =add( mx_pre , add( mx_suf ,  mul( (k-2LL) , sum)));
            res = max(res , curr );
        }
        return res%MOD;
    }
};