class Solution {
public:
    int maximum69Number (int num) {
        vector<short> digits(4 ,0);
        for (int i = 0 ; i < 4 ; i++){
            digits[i] = num%10;
            num/=10;
        }
        int ans = 0;
        for (int i = 3 ; i >= 0 ; i--){
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }
        int mul = 1000;
        for (int i = 3 ; i >= 0 ; i--){
            ans+=(mul*digits[i]);
            mul/=10;
        }
        return ans;
    }
};