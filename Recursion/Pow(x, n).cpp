class Solution {
public:
    double myPow(double x, int n) {
        bool pos = n >= 0 ;
        long double ans = x;
        if (n == 0) return ans = 1;
        long long power = abs((long long) (n));
        power--;
        while (power > 0){
            if (power&1)
                ans = ans*x , power--;
            power>>=1 , x = x*x ;
        }
        return pos ? ans : (1/ans); 
    }
};