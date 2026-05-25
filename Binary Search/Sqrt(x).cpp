class Solution {
public:
    int mySqrt(int x) {
        long long l = 0  , r = 1e5 , mid=0, ans = 0; 
        while (l <= r){
            mid = l + ((r-l)>>1);
            if (mid*mid > (long long)x)
                r = mid - 1;
            else 
                ans = mid , l = mid + 1;
        }
        return ans;
    }
};