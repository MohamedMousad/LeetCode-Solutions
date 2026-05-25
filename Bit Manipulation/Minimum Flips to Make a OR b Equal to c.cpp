class Solution {
public:
    int minFlips(int a, int b, int c) {
        int k = a | b , cnt = 0;
        for (int i = 0 ; i < 31; i++){
            if ((k&(1<<i)) != (c&(1<<i))){
                if ((c&(1<<i)) == (1<<i))
                    cnt++;
                else 
                    cnt+=((b&(1<<i)) != (c&(1<<i))) , cnt+=(a&(1<<i)) != (c&(1<<i));
            }
        }
        return cnt;
    }
};