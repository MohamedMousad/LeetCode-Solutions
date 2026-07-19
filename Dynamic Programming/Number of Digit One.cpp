class Solution {
public:
    int countDigitOne(int n) {
        long long curr = 10 , occ = 1, sum = 0 , sz = 0;
        int tmp = n;
        while(tmp){
            sz++;
            tmp/=10;
        }
        while (sz--){
            long long remains = n%curr;
            if (remains >= occ*2)
                sum+=occ;
            else {
                if (remains >= occ){
                    remains-=occ;
                    remains++;
                    sum += min(occ , remains);
                }
            }
            sum += ((n/curr))*occ;
            occ*=10;
            curr*=10;
        }
        return sum;
    }
};