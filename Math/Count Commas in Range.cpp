class Solution {
public:
    int countCommas(int n) {
        long long k = 999;
        int ans = 0 ;
        while (k < n ){
            ans+=(n-k);
            k*=1000;
        }
        return ans;
    }
};