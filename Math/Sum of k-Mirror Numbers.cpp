class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        int len = 1;
        
        while (n > 0) {
            int half = (len + 1) / 2;
            long long start = 1;
            for (int i = 1; i < half; ++i) start *= 10;
            long long end = start * 10;

            for (long long pref = start; pref < end; ++pref) {
                long long pal = pref;
                long long tail = (len % 2 == 0) ? pref : pref / 10;

                while (tail > 0) {
                    pal = pal * 10 + (tail % 10);
                    tail /= 10;
                }

                long long t = pal, rev = 0;
                while (t > 0) {
                    rev = rev * k + (t % k);
                    t /= k;
                }

                if (rev == pal) {
                    ans += pal;
                    --n;
                    if (n == 0) break;
                }
            }

            ++len;
        }

        return ans;    
    }
};