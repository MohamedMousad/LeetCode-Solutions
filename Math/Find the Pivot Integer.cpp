class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1 ; i <= n ; i++){
            int first = ((i*(i+1))>>1) , second = ((n*(n+1))>>1) - first + i;
            if ( first == second)
                return i;
        }
        return -1;
    }
};