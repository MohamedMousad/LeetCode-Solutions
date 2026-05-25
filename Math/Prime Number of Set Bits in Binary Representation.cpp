class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set <int> primes;
        int ans = 0;
        primes.insert(2);
        primes.insert(3);
        primes.insert(5);
        primes.insert(7);
        primes.insert(11);
        primes.insert(13);
        primes.insert(17);
        primes.insert(19);
        primes.insert(23);primes.insert(29);primes.insert(31);
        //primes 
        for (auto i = left ; i <= right ; i++)
        {
            if(primes.find(__popcount(i)) != primes.end())
                ans++;
        }
        return ans;
    }
};