class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1 , r = 1e5;
        while (l <= r){
            int mid = l + ((r-l)>>1);
            if ((long long )mid*mid > (long long )(num))
                r = mid - 1;
            else if (mid*mid < num)
                l = mid + 1;
            else 
                return true;
        }
        return false;
    }
};