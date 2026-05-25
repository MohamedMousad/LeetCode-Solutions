class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 2 ; i <= sqrt(num) ; i++){
            if (num % i == 0 )
                sum+=(i + num/i);
            if (sum > num)
                return false;
        }
        if (num != 1)
            sum++;
        return sum == num;
    }
};