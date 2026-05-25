class Solution {
public:
    bool good(int n){
        while (n){
            if (n%10 == 0)
                return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        int num1 = 1 , num2 = n - 1;
        while (!good(num1) || !good(num2)){
            num1++;
            num2--;
        }
        return {num1 , num2};
    }
};