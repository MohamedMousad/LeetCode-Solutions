class Solution {
    long long K  , N , mul = 1 , digits = 0 , sum = 0;
    long long getTrail(long long curr , long long N , int digit) {
        long long multiply = 1 , res  = 0;
        for (int i = digits; i > digit; i--) {
            long long d = N%10;
            N/=10;
            res +=(d*multiply) , multiply *= 10;
        }
        for (int i = digit; i > 0; i--) {
            long long d = curr%10;
            curr/=10 , res +=(d*multiply) , multiply *= 10;
        }
        return res;
    }
    bool check_prefix(long long curr , long long N , int digit) {
        if (curr > N)
            return false;
        stack<long long> s , s2;
        while (N) {
            s.push(N%10);
            N/=10;
        }
        while (curr) {
            s2.push(curr%10);
            curr/=10;
        }
        while (!s2.empty()&& !s.empty()) {
            if (s.top() == s2.top()) {
                s.pop(); s2.pop();
            }
            else {
                return false;
            }
        }
        return s2.empty();
    }
    long long rec (long long curr = 1, int digit = 1){
        long long num = curr , m = 1 , curr_sum = 1;
        for (int i = digit + 1 ; i <= digits ; i++){
            m*=10 , num*=10;
            if (i == digits && check_prefix(curr , N , digit)) {
                long long limit = getTrail(curr , N , digit);
                curr_sum += (limit - num + 1);
            }
            else if ( N >= num )
                curr_sum+=m;
        }
        if (sum == K)
            return curr/10 ;
        if (sum + curr_sum >= K){
            sum++;
            return rec(curr*10 , digit+1);
        }
        sum+=curr_sum;
        return rec(curr+1 , digit);
    }
public:
    int findKthNumber(int n, int k) {
        N = n , K = k;
        while (n){
            mul*=10;
            digits++;
            n/=10;
        }
        return rec();
    }
};