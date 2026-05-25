class Solution {
    int mod = 1e9 + 7;
    long long factorial(int n){
        long long ans = 1;
        for (int i  = 2 ; i <= n ; i++)
            ans *= i , ans%=mod;
        return ans;
    }
public:
    int countPermutations(vector<int>& complexity) {
        int mn = complexity[0] , mn2 = *min_element(complexity.begin() + 1  , complexity.end());
        if (mn2 <= mn)
            return 0 ;
        return factorial(complexity.size()-1);
    }
};