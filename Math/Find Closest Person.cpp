class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = ( x - z >= 0 ? x - z : z - x), y =( y - z >= 0 ? y - z : z - y);
        return ( x > y ? 2 : (x == y ? 0 : 1));
    }
};