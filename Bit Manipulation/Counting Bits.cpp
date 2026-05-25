class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> v(n+1 , 0);
     for (int i = 1 ; i <= n ; i++)
     {
        v[i] = __popcount(i);
     }
     return v;
    }
};