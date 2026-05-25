class Solution {
public:
    bool isHappy(int n) {
        short counter = 1;
        while (n!= 1 && counter < 100){
            int k = n , sum = 0;
            while (k) sum+=((k%10)*(k%10)) , k/=10;
            n = sum;
            counter++;
        }
        return n == 1;
    }
};