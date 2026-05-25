class Solution {
public:
    int fib(int n) {
        int f0 = 0 , f1 = 1;
        for (int i = 2; i <= n ; i++){
            int temp = f1;
            f1+=f0;
            f0 = temp;
        }
       return ( n == 0 ? f0 : f1);
    }
};