class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int sum = abs(ax1 - ax2)*abs(ay1 - ay2) + abs(bx1 - bx2)*abs(by1 - by2); 
        if (min(ax2 , bx2) > max(ax1 , bx1) && min(ay2 , by2) > max(ay1 , by1))
            sum-=((min(ax2 , bx2) - max(ax1 , bx1))*(min(ay2 , by2) - max(ay1 , by1) ));

        return sum;
    }
};