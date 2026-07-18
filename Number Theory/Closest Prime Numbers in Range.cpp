class Solution {
    vector<int> seive(int n , int left  , int right){
        vector<bool> isprime(n+5 , true);
        vector<int> res;
        isprime[0] = isprime[1] = false;
        for (int i = 2; i < n ; i++){
            if (isprime[i]){
                if (i >= left && i <= right)
                    res.push_back(i);
                int j = i + i;
                while (j <= n){
                    isprime[j] = false;
                    j+=i;
                }
            }
        }
        return res;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res = seive(1000005 , left , right);
        if (res.size() < 2)
            return {-1 , -1};
        vector<int> ans;
        int mn = INT_MAX;
        for (int i = 0 ; i < res.size() - 1 ; i++){
            if (mn > res[i+1] - res[i]){
                mn = res[i+1] - res[i];
                ans = {res[i] , res[i+1]};
            }
        }
        return ans;
    }
};