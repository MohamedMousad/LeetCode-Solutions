class Solution {
public:
    bool isUgly(int n) {
        vector<int> factors = {2 , 3 , 5};
        if (n <= 0) return false;
        for (int i = 0 ; i < 3 ; i++){
            while (n%factors[i] == 0)
                n/=factors[i];
        }
        return n == 1;
    }
};