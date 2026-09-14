class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0 ; i < 30 ; i++){
            int msk = (1LL<<i) , cnt = 0;
            while (msk&n)
                cnt++ , i++ , n-=msk , msk<<=1;
            if (cnt >= 1){
                if (cnt > 1) n+=msk;
                ans++ , i--;
            }
        }
        return ans;
    }

};