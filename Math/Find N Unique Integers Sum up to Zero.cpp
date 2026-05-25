class Solution {
public:
    vector<int> sumZero(int& n) {
        vector<int> a(n);
        if (n&1) n--;
        for (short i = 1 ; i <= n ;){
            a[i-1] = i;
            a[i] = -i;
            i+=((short)2);
        }
        return a;
    }
};