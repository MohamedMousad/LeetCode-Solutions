class Solution {
public:
    int totalMoney(int n) {
        int divisions = n / 7 , remainder = n%7;
        int sum = ((7*8) >> 1)*divisions + ( (remainder*(remainder+1)) >> 1 );
        if (divisions >= 1 )
            sum = sum + (7*(((divisions - 1)*(divisions)) >> 1)) + (divisions*remainder);
        return sum ;
    }
};