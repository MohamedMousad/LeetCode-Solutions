class Solution {
public:
    long long countCommas(long long n) {
        long long k = 999 , ans = 0 ;
        while (k < n ){
            ans+=(n-k);
            k*=1000LL;
            k+=999;
        }
        return ans;
    }
};