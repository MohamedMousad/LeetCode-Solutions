class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1 , r = 1e6 , ans = 1;
        while (l <= r){
            int mid = l + ((r-l)>>1);
            if ((long long )mid*(mid+1)/2 <= (long long )(n))
                l = mid + 1 ,  ans = mid;
            else
                r = mid - 1;
        }
        return ans;
    }
};