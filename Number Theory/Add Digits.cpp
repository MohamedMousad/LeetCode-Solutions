class Solution {
public:
    int addDigits(int num) {
        int num2 = 0;
        while (num > 9 ){
            while (num > 0){
                num2+=(num%10);
                num/=10;
            }
            num = num2 ;
            num2 = 0;
        }
        return num;
    }
};