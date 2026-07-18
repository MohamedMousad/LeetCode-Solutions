class Solution {
    int seive(int n){
        int cnt = 0;
        vector<bool> isprime(n+5 , true);
        isprime[0] = isprime[1] = false;
        for (int i = 2; i < n ; i++){
            if (isprime[i]){
                cnt++;
                int j = i + i;
                while (j <= n){
                    isprime[j] = false;
                    j+=i;
                }
            }
        }
        return cnt;
    }
public:
    int countPrimes(int n) {
        return seive(n);
    }
};