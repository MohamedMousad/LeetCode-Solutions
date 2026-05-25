class Solution {
public:
    int hammingDistance(int x, int y) {
       
        return __popcount(x^y);
    }
};  