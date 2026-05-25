class Solution {
public:
    bool isThree(int n) {
        int cnt = 2;
        for (int i = 2 ; i*i <= n  ; i++ ){
            if (n % i == 0)
                cnt+=2;
            if (i*i == n) cnt--;
        }
        return cnt == 3;
    }
};