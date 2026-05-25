class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd1 = (n >> 1) + (n&1)  , odd2 = (m >> 1) + (m&1)  , even1 = (n >> 1) , even2 = (m >> 1) ;
        return ((odd1*even2) + (odd2*even1));
    }
};