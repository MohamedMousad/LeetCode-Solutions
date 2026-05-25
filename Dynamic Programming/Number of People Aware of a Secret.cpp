class Solution {
    long long MOD = 1e9+7;
    long long add(long long a,long long b)
    {
        return ((a%MOD)+(b%MOD))%MOD;
    }
    long long sub(long long a,long long b)
    {
        return (((a-b)%MOD)+MOD)%MOD;
    }
public:  
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long mod = 1e9+7;
        vector<long long> active_users(n+forget+5) , forgets (n+forget+5);
        long long total_sum = 1;
        active_users[delay+1]++; active_users[forget+1]--; forgets[forget+1]++;
        long long prefix_active = 0;
        for (int i = 2 ; i <= n ; i++) {
            prefix_active = add(prefix_active, active_users[i]);  
            active_users[i+delay] = add(active_users[i+delay], prefix_active);
            active_users[i+forget] = sub(active_users[i+forget], prefix_active);
            forgets[i+forget] = add(forgets[i+forget], prefix_active);
            total_sum = add(total_sum, sub(prefix_active, forgets[i]));
        }
        return total_sum;
    }
};