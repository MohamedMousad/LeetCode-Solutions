class Solution {
    #define ll long long
    ll MOD = 1e9 + 7;
    ll mul(ll a,ll b)
    {
        return ((a%MOD)*(b%MOD))%MOD;
    }
    ll add(ll a,ll b)
    {
        return ((a%MOD)+(b%MOD))%MOD;
    }
    ll sub(ll a,ll b)
    {
        return (((a-b)%MOD)+MOD)%MOD;
    }
    ll power(ll b,ll n)
    {
        b%=MOD;
        ll s=1;
        while(n)
        {
            if(n%2==1)s=s*b%MOD;
            b=b*b%MOD;
            n/=2;
        }
        return s;
    }
public:
    int strStr(string haystack, string needle) {
        ll hash1 = 0 , hash2 = 0;
        for(int i = 0 ; i < needle.size() ; i++){
            hash1 = mul(hash1 ,26LL);
            hash1= add(hash1 , needle[i]);
        }
        for(int i = 0 ; i < haystack.size() ; i++){
            if (i >= needle.size()){
                long long diff = mul( power(26LL , needle.size() - 1) , haystack[i - needle.size()]);
                hash2 = sub(hash2 , diff);
            }
            hash2=mul(hash2 , 26LL);
            hash2=add(hash2 , haystack[i]);
            if (hash1 == hash2)
                return i - needle.size() + 1;
        }
        return -1;
    }
};