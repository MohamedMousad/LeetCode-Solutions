class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long sum = 0;
        for (int i = 30 ; i >= 0 ; i--){
            if (((1LL << i)&left) == ((1LL << i)&right))
                sum+=((1LL<<i)&left);
            else 
                break;
        }
        return sum;
    }
};