class Solution {
public:
    int climbStairs(int n) {
        int last = 1 , first = 1;
        for (int i = n-2; i >= 0 ; i--){
            int temp = first;
            first = last + first;
            last = temp;
        }
        return first;
    }
};